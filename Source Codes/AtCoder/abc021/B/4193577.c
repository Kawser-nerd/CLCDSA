#include<stdio.h>

int main(){
    int N,a,b,K,flag=0,i,j;
    int P[100];

    scanf("%d",&N);
    scanf("%d %d",&a,&b);
    scanf("%d",&K);
    for(i=1;i<=K;i++){
        scanf("%d",&P[i]);
    }
    P[0]=a; P[K+1]=b;
    for(i=0;i<K+2;i++){
        for(j=i+1;j<K+2;j++){
            if(P[i]==P[j]){
                flag = 1;
            }
        }
    }
    if(flag==0){
        printf("YES\n");
    }else{printf("NO\n");}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&K);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&P[i]);
         ^