# 카운팅 정렬(Counting Sort)

카운팅 정렬(Counting Sort)은 정수나 정수로 표현할 수 있는 객체를 정렬하는 알고리즘으로 비교 기반 정렬 알고리즘이 아니다.

시간 복잡도가 O(n + k)로, 여기서 n은 배열의 크기이고 k는 배열 요소 중 최대값이다.

카운팅 정렬은 데이터의 크기가 제한되어 있는 경우 매우 효율적이다.

### 예시

```
# 예제 리스트: [4, 2, 2, 8, 3, 3, 1]

1. 주어진 배열에서 요소의 최대값을 탐색.
    - max = 8

2. 크기가 (max + 1)인 카운트 배열을 생성하고 초기화.
    - 카운트 배열: [0, 0, 0, 0, 0, 0, 0, 0, 0]

3. 주어진 배열을 순회하며 각 요소의 빈도를 카운트 배열에 기록.
    - 카운트 배열: [0, 1, 2, 2, 1, 0, 0, 0, 1]

4. 카운트 배열을 수정하여 각 요소의 정렬된 위치를 결정.
    - 카운트 배열: [0, 1, 3, 5, 6, 6, 6, 6, 7]

5. 주어진 배열을 순회하며 정렬된 배열에 요소를 배치.
    - 정렬된 배열: [1, 2, 2, 3, 3, 4, 8]
```

### **카운팅 정렬 코드**
```c
#include <stdio.h>

int main()
{   
    int n = 0;
    scanf("%d", &n);
    
    int data[n];
    int max = 0;
    
    //배열 입력
    for (int i = 0; i<n; i++){
        scanf("%d", &data[i]);
    }
    //최댓값 찾기
    for (int i = 0; i<n; i++){
        if(max<data[i]){
            max = data[i];
        }
    }
    //요소 카운트 배열 선언
    int count[max+1];
    //정렬 위치 배열 선언
    int new_count[max+1];
    //초기화
    for (int i = 0; i < max+1; i++) {
        count[i] = 0;
        new_count[i] = 0;
    }
    //요소 카운트
    for(int i = 0; i<n; i++){
        count[data[i]]++;
    }
    //정렬된 위치 찾기
    for (int i = 0; i<max+1; i++){
        new_count[0] = count[0];
        new_count[i+1] = new_count[i] + count[i+1];
    }
    
    int sort[n];
    //정렬
    for(int i = 0; i<n; i++){
        sort[new_count[data[i]]-1] = data[i];//정렬 위치는 1부터 시작 인덱스는 0부터 시작. -1 해줘야함.
            new_count[data[i]]--;//정렬 수 개수 감소
    }
    
    for (int i = 0; i<n; i++){
        printf("%d ", sort[i]);
    }

    return 0;
}
```