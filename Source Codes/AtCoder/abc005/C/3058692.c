#include<stdio.h>

int main(void){

    int T, N, M;
    scanf("%d%d", &T, &N);            //T, N???
    int A[N];
    for(int i=0;i<N;i++){             //A[]???
        scanf("%d",&A[i]);
    }
    scanf("%d", &M);                  //M???
    int B[M];
    for(int j=0;j<M;j++){             //B[]???
        scanf("%d", &B[j]);
    }
    
    int k=0,p=0;                      //k:????????, p:???????????
    
    for(int j=0;j<M;j++){
        if(k==N) break;                //???????????break
        else if((B[j]-A[k])<0)break;   //??????break
        else{                          //T?????????????
            while((B[j]-A[k])>T){
                k++;
            }
            if((B[j]-A[k])<0) break;   //?????????????break
            else {
                p++;                   //???????????
                k++;                   //????1???
            }
        }
    }
    if(p==M)printf("yes\n");
    else printf("no\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &T, &N);            //T, N???
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&A[i]);
         ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &M);                  //M???
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &B[j]);
         ^