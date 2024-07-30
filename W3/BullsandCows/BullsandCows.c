#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//입력값 중복 검사 함수
int isUnique(int a, int b, int c) {
    return (a != b) && (b != c) && (c != a);
}

// 숫자가 0에서 9 사이인지 확인하는 함수
int isValidNumber(int num) {
    return num >= 0 && num <= 9;
}

//컴퓨터 랜덤값 생성 로직 구현
void generateCpuNum(int *a, int *b, int *c){
    srand(time(NULL)); // 난수 시드 설정

    *a = rand() % 10;
    do {
        *b = rand() % 10;
    } while(*b == *a);
    do {
        *c = rand() % 10;
    } while(*c == *a || *c == *b);
}

//플레이어 입력값 받는 함수
void playerInputNum(int *a, int *b, int *c){
    do {
        printf("0~9까지의 숫자 3개를 중복 없이 입력해주세요. (모든 숫자 사이에는 공백을 입력해 주세요)\n");
        scanf("%d %d %d", a, b, c);

        if(!isValidNumber(*a)||!isValidNumber(*b)||!isValidNumber(*c)){
            printf("0~9까지의 숫자로 입력해주세요.\n");
        }
        
        //여기에 숫자 외의 것을 입력했을 때 오류 출력하는 로직도 추가하면 좋을 듯.

        if(!isUnique(*a, *b, *c)){
            printf("중복된 숫자가 있습니다. 다시 입력해주세요.\n");
        }
    } while(!isUnique(*a, *b, *c));
}

//공격 선택 함수
void chooseFirstAttack(int *a){
    srand(time(NULL)); // 난수 시드 설정

    *a = rand() % 2;
}

//숫자야구 로직 구현 함수
void calBullsandCows(int a, int b, int c, int x, int y, int z, int *strikes, int *balls){
    *strikes = 0;
    *balls = 0;
    if(a == x){
        (*strikes)++;
    }
    if(b == y){
        (*strikes)++;
    }
    if(c == z){
        (*strikes)++;
    }
    if(a == y || a == z){
        (*balls)++;
    }
    if(b == x || b == z){
        (*balls)++;
    }
    if(c == x || c == y){
        (*balls)++;
    }
}


int main()
{
    int player_num = 0;
    char player_name1[20] = "";
    char player_name2[20] = "";
    char attack_player[20] = "";
    char defence_player[20] = "";
    char play_continue[10] = "Y";
    
    int player1_win = 0;
    int player2_win = 0;

    int strikes = 0;
    int balls = 0;
    int outCount = 0;


    //숫자야구 구조체
    typedef struct {
        int first_num;
        int second_num;
        int third_num;
    } Numbers;

    Numbers defence;
    Numbers attack;
    
    
    //플레이 인원 체크
    do{
        printf("플레이 인원을 입력해주세요. (최대 2명)\n");
        scanf("%d", &player_num);

        if(player_num != 1 && player_num != 2){
            printf("잘못된 플레이어 수 입니다. 다시 입력해주세요.\n");
        }
        
    } while(player_num != 1 && player_num != 2);
    
    //1명일 때
    if(player_num == 1){
        printf("플레이어의 이름을 입력해주세요.\n");
        scanf("%s", player_name1);
        
        while(strcmp(play_continue, "Y") == 0){
            printf("%s의 선공입니다.\n", player_name1);
            printf("게임을 시작합니다.\n");
    
            //컴퓨터 랜덤값 생성 함수 호출
            generateCpuNum(&defence.first_num, &defence.second_num, &defence.third_num);
    
            while(outCount<3){
    
                //플레이어 입력값 함수 호출
                playerInputNum(&attack.first_num, &attack.second_num, &attack.third_num);
    
                //숫자 야구 함수 호출
                calBullsandCows(defence.first_num, defence.second_num, defence.third_num, attack.first_num, attack.second_num, attack.third_num, &strikes, &balls);
    
                //결과
                if(strikes == 0 && balls == 0){
                    printf("OUT\n");
                    outCount++;
                } else{
                    printf("%dS %dB\n", strikes, balls);
                }
    
                if (strikes<3){
                    strikes = 0;
                    balls = 0;
                } else{
                    player1_win++;
                    printf("%s의 승리! %d:%d입니다.", player_name1, player1_win, player2_win);
                    break;
                }
            }
            
            if(outCount == 3){
                player2_win++;
                printf("컴퓨터의 승리! %d:%d입니다.", player2_win, player1_win);
            }
            
            printf("다시 플레이 하시겠습니까?");
            scanf("%s", play_continue);
            
            //초기화
            strikes = 0;
            balls = 0;
            outCount = 0;
        }
    
        } else if(player_num == 2){
            
            printf("첫번째 플레이어의 이름을 입력해주세요.\n");
            scanf("%s", player_name1);
            printf("두번째 플레이어의 이름을 입력해주세요.\n");
            scanf("%s", player_name2);
    
            while(strcmp(play_continue, "Y") == 0){
                //선공 선택 로직
                int att = 0;
                chooseFirstAttack(&att);
                if(att == 1){
                    strcpy(attack_player, player_name1);
                    strcpy(defence_player, player_name2);
                }else{
                    strcpy(attack_player, player_name2);
                    strcpy(defence_player, player_name1);
                }
        
                printf("%s의 선 공격입니다! %s은(는) 0~9까지의 숫자 3개를 중복 없이 입력해주세요.\n", attack_player, defence_player);
                playerInputNum(&defence.first_num, &defence.second_num, &defence.third_num);
                printf("게임을 시작합니다.\n");
        
                while(outCount<3){
        
                    //플레이어 입력값 함수 호출
                    playerInputNum(&attack.first_num, &attack.second_num, &attack.third_num);
        
                    //숫자 야구 함수 호출
                    calBullsandCows(defence.first_num, defence.second_num, defence.third_num, attack.first_num, attack.second_num, attack.third_num, &strikes, &balls);
        
                    //결과
                    if(strikes == 0 && balls == 0){
                        printf("OUT\n");
                        outCount++;
                    } else{
                        printf("%dS %dB\n", strikes, balls);
                    }
        
                    if (strikes<3){
                        strikes = 0;
                        balls = 0;
                    } else{
                        if(strcmp(attack_player, player_name1) == 0){
                            player1_win++;
                            break;
                        } else{
                            player2_win++;
                            break;
                        }
                    }
                }
                
                if(outCount == 3){
                    
                    if(strcmp(defence_player, player_name1) == 0){
                        player1_win++;
                        printf("%s의 승리! %d:%d입니다.", defence_player, player1_win, player2_win);
                    } else{
                        player2_win++;
                        printf("%s의 승리! %d:%d입니다.", defence_player, player2_win, player1_win);
                    }
                }else{
                    if(strcmp(attack_player, player_name1) == 0){
                        printf("%s의 승리! %d:%d입니다.", attack_player, player1_win, player2_win);
                    }else{
                        printf("%s의 승리! %d:%d입니다.", attack_player, player2_win, player1_win);
                    }
                }
                
                printf("다시 플레이 하시겠습니까? Y/N으로 입력해주세요.");
                scanf("%s", play_continue);
                //초기화
                strikes = 0;
                balls = 0;
                outCount = 0;
            }   
        }
    return 0;
}
