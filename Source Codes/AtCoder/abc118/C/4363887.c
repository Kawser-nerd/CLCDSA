#include<stdio.h>

int eucalg(int a,int b){
    if(0<a && a<b) eucalg(a,(b%a));
    else if(0<b && a>b) eucalg((a%b),b);
    else if (a==0) return b;
    else return a;
}

int main(void){
    int Maxnumber=100000,MaxHP=1000000000,N,A[Maxnumber+1];
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&(A[i]));
    }
    for(int i=1;i<=N;i++){
        A[1]=eucalg(A[1],A[i]);
    }
    printf("%d",A[1]);

    return 0;
}
/*test
1.
4
2 10 8 40
->2
2.
4
5 13 8 1000000000
->1
3.
3
1000000000 1000000000 1000000000
->1000000000
*/ ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&(A[i]));
         ^