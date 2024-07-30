# 버블정렬(Bubble Sort)

버블정렬은 원소의 이동들이 거품이 수면으로 올라오는 듯한 모습을 보여 지어진 이름이다.

<center>

[![Video Label](https://i.ytimg.com/vi/Cq7SMsQBEUw/hqdefault.jpg)](https://youtu.be/Cq7SMsQBEUw)

</center> 

버블정렬은 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘으로 크기가 순서대로 되어있지 않으면 서로 자리를 교환한다.

### 예시

|  |&nbsp;&nbsp;&nbsp;10&nbsp;&nbsp;&nbsp;| &nbsp;&nbsp;&nbsp;17&nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp;9&nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp;6&nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp;45&nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp;20&nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp;3&nbsp;&nbsp;&nbsp; |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1번째 | 10 | 17 |  |  |  |  |  |
|  |  | 9 | 17 |  |  |  |  |
|  |  |  | 6 | 17 |  |  |  |
|  |  |  |  | 17 | 45 |  |  |
|  |  |  |  |  | 20 | 45 |  |
|  |  |  |  |  |  | 3 | 45 |
| 6번 비교 | 10 | 9 | 6 | 17 | 20 | 3 | 45 |
| 2번째 | 9 | 10 |  |  |  |  |  |
|  |  | 6 | 10 |  |  |  |  |
|  |  |  | 10 | 17 |  |  |  |
|  |  |  |  | 17 | 20 |  |  |
|  |  |  |  |  | 3 | 20 | 45 |
| 5번 비교 | 9 | 6 | 10 | 17 | 3 | 20 | 45 |
| 3번째 | 6 | 9 |  |  |  |  |  |
|  |  | 9 | 10 |  |  |  |  |
|  |  |  | 10 | 17 |  |  |  |
|  |  |  |  | 3 | 17 | 20 | 45 |
| 4번 비교 | 6 | 9 | 10 | 3 | 17 | 20 | 45 |
| 4번쨰 | 6 | 9 |  |  |  |  |  |
|  |  | 9 | 10 |  |  |  |  |
|  |  |  | 3 | 10 | 17 | 20 | 45 |
| 3번 비교 | 6 | 9 | 3 | 10 | 17 | 20 | 45 |
| 5번째 | 6 | 9 |  |  |  |  |  |
|  |  | 3 | 9 |  |  |  |  |
| 2번 비교 | 6 | 3 | 9 | 10 | 17 | 20 | 45 |
| 6번째 | 3 | 6 |  |  |  |  |  |
| 1번 비교 | 3 | 6 | 9 | 10 | 17 | 20 | 45 |

<br>

**반복 1회 실행 시 최댓값(오름차순)/최솟값(내림차순)이 맨 뒤로 정렬되어** 반복 2회부터는 정렬에서 제외된다. 이렇게 정렬을 1회씩 반복할 때마다 제외되는 데이터가 하나씩 늘어나게 된다.

예시와 같이 원소가 7개라면 6번 반복 실행하고, 1회 실행마다 원소 비교는 6회 ~ 1회까지 진행된다.

⇒ 원소가 n개라면 n-1번 반복 실행하고, 1~n-1번까지 n-1번부터 1번까지 원소의 비교가  진행된다.





### **이중 for문을 활용한 버블정렬 구현**

```c
#include <stdio.h>

int main(){

    int n = 0;
    scanf("%d", &n);
    
    int data[n]; //n개의 값을 가지는 배열 선언
    for(int i=0; i<n; i++){
        scanf("%d", &data[i]);
    }
    
    int temp = 0;//임시로 데이터 저장할 변수 선언

    for(int i = 0; i < n-1; i++){//n-1만큼 반복
    	for(int j = 0; j< n-1-i; j++){//n-1만큼 비교하다 마지막 반복엔 1번 비교
    		if(data[j] > data[j+1]){
    			temp = data[j]; //data[j]를 잠시 저장
    			data[j] = data[j+1]; //data[j+1]을 data[j]의 위치로 이동
    			data[j+1] = temp;	//data[j+1]의 자리에 저장해둔 data[j]를 입력.
    			//큰 숫자가 뒤로 밀리는 오름차순 완성
    		}
    	}
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", data[i]);
    }
    
    return 0;
}
```

```c
#include <stdio.h>

	int main() {
	  
	  int n = 0;
    scanf("%d", &n);
    
    int data[n]; 
    for(int i=0; i<n; i++){
        scanf("%d", &data[i]);
    }
    
    int temp = 0;

    for(int i = 0; i < n-1; i++){
    	for(int j = 0; j< n-1-i; j++){
    		if(data[j] < data[j+1]){//부등호 방향을 반대로 바꾸면
    			temp = data[j];
    			data[j] = data[j+1];
    			data[j+1] = temp;
    			//큰 숫자가 앞으로 오는 내림차순 완성
    		}
    	}
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", data[i]);
    }
    
    return 0;
}
```