#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
        char S[100][100],W[100],s[10],X,Y;
    scanf("%d",&A);
    for(i=0;i<A;i++){
        scanf("%d",&v[i]);
    }
    min_i=0;
    for(i=1;i<A;i++){
        if(v[i]>v[min_i]){
            min_i=i;
        }
    }
    v[min_i]=v[min_i]/2;
    for(i=0;i<A;i++){
        cou+=v[i];
    }
    printf("%d",cou);
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&v[i]);
         ^