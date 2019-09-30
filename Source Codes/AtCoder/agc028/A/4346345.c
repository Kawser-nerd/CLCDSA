#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))

//Prototype
void quicksort(long list[], long left, long right);

long gcm(long,long);

int main() {
    long n,m;
    char s[100001];
    char t[100001];
    //input
    scanf("%ld%ld\n%s\n%s",&n,&m,s,t);

    //calculation
    //quicksort(array, 0, n-1);

    //Output
    int flag = 1;
    long g = gcm(max(n,m),min(n,m));
    for(long i = 0; i < g ; i++ ){
        if(s[i*n/g] != t[i*m/g]){
            //printf("s[%ld] = %c , t[%ld] = %c\n",i*m/g,s[i*m/g],i*n/g,t[i*n/g]);
            flag = 0;
        }
    }

    printf("%ld\n", flag ? m*n/g : -1);

    return 0;
}


long gcm(long x,long y){
    if(y == 0){
        return x;
    }else{
        return gcm(y,x%y);
    }
}

void quicksort(long list[], long left, long right)
{
    long i, last;
    long temp;

    if (left >= right)
        return;

    last = left;
    for (i=left+1; i <= right; i++){
        if (list[i] < list[left] ){
            last++;
            temp=list[last];
            list[last]=list[i];
            list[i]=temp;
        }
    }

    temp=list[left];
    list[left]=list[last];
    list[last]=temp;

    quicksort(list, left, last-1);
    quicksort(list, last+1, right);
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld\n%s\n%s",&n,&m,s,t);
     ^