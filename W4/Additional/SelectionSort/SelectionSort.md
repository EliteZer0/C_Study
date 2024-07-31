# 선택 정렬(Selection Sort)

선택 정렬(Selection Sort)은 간단한 비교 기반 정렬 알고리즘이다.

선택 정렬은 매 반복마다 리스트에서 최소값을 선택해서 교환하기 때문에 선택 정렬이라고 불린다.

선택 정렬의 시간 복잡도는 O(n<sup>2</sup>)이다. 때문에 리스트의 크기가 커질수록 비효율적이다.

### 예시
|  |&nbsp;&nbsp;&nbsp; 5 &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp; 2 &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp; 9 &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp; 1 &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp; 5 &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp; 6 &nbsp;&nbsp;&nbsp;|
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1회 | 1 | 2 | 9 | 5 | 5 | 6 |
| 2회 | 1 | 2 | 9 | 5 | 5 | 6 |
| 3회 | 1 | 2 | 5 | 9 | 5 | 6 |
| 4회 | 1 | 2 | 5 | 5 | 9 | 6 |
| 5회 | 1 | 2 | 5 | 5 | 6 | 9 |

주어진 리스트에서 가장 작은 요소 탐색.

그 요소를 리스트의 첫 번째 요소와 교환.

리스트의 첫 번째 요소를 제외한 나머지 리스트에서 가장 작은 요소를 탐색.

그 요소를 리스트의 두 번째 요소와 교환.

이 과정을 끝까지 반복.
<br>
<br>

### **선택 정렬 코드** 

```c
#include <stdio.h>
#include <limits.h>

int main()
{   
    int n = 0;
    scanf("%d", &n);
    
    int data[n];
    
    for (int i = 0; i<n; i++){
        scanf("%d", &data[i]);
    }
    
    for (int i = 0; i<n; i++){
        int min = INT_MAX;//요소와 비교하기 위한 int형 최댓값 설정
        int minIndex = 0;
        for(int j = i; j<n; j++){
            if(min>data[j]) {
                min = data[j];//비교한 요소가 작으면 최솟값에 요소 저장
                minIndex = j;//인덱스 번호 저장
            }
        }
        int temp = data[i]; //현재 요소 임시 저장
        data[i] = min;//현재 인덱스에 최솟값 저장
        data[minIndex] = temp;//최솟값 인덱스에 현재 요소 저장
    }
    
    for (int i = 0; i<n; i++){
        printf("%d ", data[i]);
    }

    return 0;
}
```

```c
#include <stdio.h>

int main()
{   
    int n = 0;
    scanf("%d", &n);
    
    int data[n];
    
    for (int i = 0; i<n; i++){
        scanf("%d", &data[i]);
    }
    
    for (int i = 0; i<n; i++){
        int minIndex = i;//i번째 반복 시 최솟값 저장할 인덱스

        for(int j = i; j<n; j++){
            if(data[minIndex]>data[j]) {
                minIndex = j;//최솟값 위치 저장
            }
        }

        int temp = data[i];//현재 요소 임시 저장
        data[i] = data[minIndex];//현재 인덱스에 최솟값 저장
        data[minIndex] = temp;//최솟값 인덱스에 현재 요소 저장
    }
    
    for (int i = 0; i<n; i++){
        printf("%d ", data[i]);
    }

    return 0;
}
```