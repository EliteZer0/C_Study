# [CODEUP C언어 기초 100제](https://codeup.kr/problemsetsol.php?psid=23)

### 78번

```c
#include <stdio.h>

int main()
{   
    int n = 0;
    int sum = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        if(i%2==0) sum=sum+i;
    }
    printf("%d", sum);
    return 0;
}
```

### 79번 

```c
#include <stdio.h>

int main()
{   
    char c;
    while (c != 'q'){
        scanf("%c", &c);
        printf("%c", c);    
    }
    return 0;
}
```

### 80번

```c
#include <stdio.h>

int main()
{   
    int n = 0;
    int sum = 0;
    int i;
    scanf("%d", &n);
    
    for(i=1; sum < n; i++)
    {
        sum += i;
    }
    printf("%d", i-1); //루프가 끝날 때 1이 더해지므로 1 빼야함
    return 0;
}
```

### 81번

```c
#include <stdio.h>

int main()
{   int n, m;
    scanf("%d %d", &n, &m);
    for(int k=1; k<=n; k++){
        for(int l=1; l<=m; l++){
            printf("%d %d\n", k, l);
        }
    }
    return 0;
}
```

### 82번

```c
#include <stdio.h>

int main()
{   int n;
    scanf("%x", &n);
    for(int k=1; k<16; k++){
        printf("%X\*%X\=%X\n", n,k,n*k);
    }
    return 0;
}
```

### 83번

```c
#include <stdio.h>

int main()
{   int n;
    scanf("%d", &n);
    for(int k=1; k<=n; k++){
        if(k % 3 == 0){
            printf("X");
        }
        else{
            printf("%d", k);
        }
        printf(" ");
    }
    return 0;
}
```

### 84번

```c
#include <stdio.h>

int main(){
    int r, g, b;
    int c = 0;
    scanf("%d %d %d", &r, &g, &b);
    for(int i=0; i<r; i++){
        for(int j=0; j<g; j++){
            for(int k=0; k<b; k++){
                printf("%d %d %d\n", i, j, k);
                c++;
            }
        }
    }
    printf("%d", c);
    return 0;
}
```

### 85번

```c
#include <stdio.h>

int main()
{   double h, b, c, s = 0;
    scanf("%lf %lf %lf %lf", &h, &b, &c, &s);
    double bit = h*b*c*s;
    double byte = bit/8;
    double kb = byte/1024;
    double mb = kb/1024;
    printf("%.1lf MB\n", mb);

    return 0;
}
```

### 86번

```c
#include <stdio.h>

int main()
{   double r, g, b;
    scanf("%lf %lf %lf", &r, &g, &b);
    double mb = r*g*b/8/1024/1024;
    printf("%.2lf MB", mb);
    return 0;
}
```

### 87번

```c
#include <stdio.h>

int main(){
    int n, s=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        s+=i;
        if(s>=n)
        break;
    } 
    printf("%d", s);
}
```

### 88번

```c
#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        if(i%3 == 0)
            continue;
            printf("%d ", i);
        
    } 
}
```

### 89번

```c
#include <stdio.h>

int main(){
    int a, d, n = 0;
    scanf("%d %d %d", &a, &d, &n);
    int answer = a+d*(n-1);
    printf("%d", answer);
}
```

### 90번

```c
#include <stdio.h>
#include <math.h>

int main(){
    long int a, r, n = 0;
    scanf("%ld %ld %ld", &a, &r, &n);
    long int answer = a*pow(r,n-1);
    printf("%ld", answer);
}
```

### 91번

```c
#include <stdio.h>

int main(){
    long long int a, m, d, n = 0;
    scanf("%lld %lld %lld %lld", &a, &m, &d, &n);
    for(int i = 1; i<n ; i++){
        a *= m;
        a += d;
    }
    printf("%lld", a);
}
```

### 92번

```c
#include <stdio.h>

int main(){
    int a, b, c = 0;
    int day = 1;
    scanf("%d %d %d", &a, &b, &c);
    while(day%a != 0 || day%b != 0 || day%c !=0) day ++;
    printf("%d", day);
}
```

### 93번

```c
#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int a[24] = {};
    int t = 0;
    for(int i = 1; i<=n; i++){
        scanf("%d", &t);
        a[t] += 1;
    }
    for(int i =1; i<=23; i++){
        printf("%d ", a[i]);
    }
}
```

### 94번

```c
#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int a[10000] = {};
    int t = 0;
    for(int i = 1; i<=n; i++){
        scanf("%d", &t);
        a[n-i+1] = t;
    }
    for(int i =1; i<=n; i++){
        printf("%d ", a[i]);
    }
}
```

### 95번

```c
#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int a[10000] = {};
    int t = 0;
    int answer = 24;
    for(int i = 1; i<=n; i++){
        scanf("%d", &t);
        a[i] = t;
        if(answer>a[i]) answer = a[i];
    }
    printf("%d ", answer);
}
```

### 96번

```c
#include <stdio.h>

int main(){
    int a[20][20] = {};
    int n, x, y = 0;
    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++){
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
    }
    for(int i = 1; i<20; i++){
        for(int j = 1; j<20; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
```

### 97번

```c
#include <stdio.h>

int main(){
    int a[20][20] = {};
    int n, x, y = 0;
    
    for(int i = 1; i<20; i++){
        for(int j = 1; j<20; j++){
            scanf("%d ", &a[i][j]);
        }
    }
    
    scanf("%d", &n);
    
    for(int i = 0; i<n ; i++){
        scanf("%d %d", &x, &y);
        
        for(int j = 1; j<20 ; j++){
            if(a[x][j] == 0) {
                a[x][j] = 1;
            }
            else {
                a[x][j] = 0;
            }
        }
        for(int k = 1; k<20; k++){
            if(a[k][y] == 0){
                a [k][y] = 1;
            }
            else{
                a[k][y] = 0;
            }
        }
    }
    
    for(int i = 1; i<20; i++){
        for(int j = 1; j<20; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

### 98번

```c
#include <stdio.h>

int main(){
    int w, h = 0;
    scanf("%d %d", &w, &h);
    int a[100][100] = {};
    int n, l, d, x, y = 0;
    
    scanf("%d", &n);
    
    for(int i = 0; i<n ; i++){
        scanf("%d %d %d %d", &l, &d, &x, &y);
        if(d==0){
            for(int p = 0; p<l ; p++){
                a[x][y+p] = 1;
            }
        }
        else{
            for(int q = 0; q<l ; q++){
                a[x+q][y] = 1;
            }
        }
    }
    
    for(int i = 1; i<=w; i++){
        for(int j = 1; j<=h; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

### 99번

```c
#include <stdio.h>

int main(){
    int a[11][11] = {};
    for(int i = 1; i<=10; i++){
        for(int j = 1; j<=10; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    int p = 2;
    int q = 2;
    while(a[p][q] < 2 && p<10 && q<10 && q>1){
        if (a[p][q] == 0) {
            a[p][q] = 9;
            q++;
        } 
        else if (a[p][q] == 1) {
            p++;
            q--;
            a[p][q] = 9;
            q++;
        }
    }
    
    for(int m = 1; m<=10; m++){
        for(int n = 1; n<=10; n++){
            printf("%d ", a[m][n]);
        }
        printf("\n");
    }
    return 0;
}
```