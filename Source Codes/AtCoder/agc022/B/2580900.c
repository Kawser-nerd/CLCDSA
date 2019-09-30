#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))


//for
#define REP(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define REPS(i,n) for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define RREPS(i,n) for(int i=(int)(n);i>0;i--)
#define FOR(i,s,n) for(int i=(int)(s),i##_len=(int)(n);i<i##_len;i++)

//printf
#define PRINTD(d) printf("%d\n",(d))
#define PRINTL(d) printf("%lld\n",(d))

//Prototype
void bubbleSort(int* N, int len);
void Swap(int *a, int *b);


int main() {
    int n;
    int youi[] = {2,3,4,6,8,9,10,12};
    int last = 0;
    //input
    scanf("%d",&n);
    
    //calculation
    
    if(n == 3){
        printf("2 5 63");
        goto ending;
    }
    
    for(int i = 0; i <= n/8 - 1; i++){
        last = 12*i;
        for(int j = 0; j <= 7 ; j++){
            printf("%d ",last+youi[j]);
        }
    }
    last += 12;
    
    switch (n%8) {
        case 1:
            printf("%d ",last+6);
            break;
        case 2:
            printf("%d ",last+6);
            printf("%d ",last+12);
            break;
        case 3:
            printf("%d ",last+6);
            printf("%d ",last+3);
            printf("%d ",last+9);
            break;

        case 4:
            printf("%d ",last+2);
            printf("%d ",last+3);
            printf("%d ",last+9);
            printf("%d ",last+10);
            break;
        case 5:
            printf("%d ",last+6);
            printf("%d ",last+3);
            printf("%d ",last+9);
            printf("%d ",last+4);
            printf("%d ",last+8);
            break;
        case 6:
            printf("%d ",last+6);
            printf("%d ",last+3);
            printf("%d ",last+9);
            printf("%d ",last+4);
            printf("%d ",last+8);
            printf("%d ",last+12);
            break;
        case 7:
            printf("%d ",last+6);
            printf("%d ",last+3);
            printf("%d ",last+9);
            printf("%d ",last+4);
            printf("%d ",last+8);
            printf("%d ",last+2);
            printf("%d ",last+10);
            break;
        default:
            break;
    }
    
    ending :
    
    return 0;
}


//BubbleSort
void bubbleSort(int* N, int len){
    int i,j;
    
    for(i=0; i<len; i++){
        for(j=len-1; j>i; j--){
            if(N[j] < N[j-1]){
                Swap(&N[j],&N[j-1]);
            }
        }
    }
}

//general function
void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
} ./Main.c: In function ‘main’:
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^