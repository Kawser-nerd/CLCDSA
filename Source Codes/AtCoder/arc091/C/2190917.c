#include <stdio.h>


    int writelist[300000];
    int unko;
    
int write(int N,int x){
    if(unko>=N){
        for(int i=0;i<N;i++){
            if(writelist[i]>N||writelist[i]<=0){printf("-1");return 1;}
        }
        for(int i=0;i<N;i++)printf("%d ",writelist[i]);
        return 1;
    }
    else{
        writelist[unko]=x;
        unko++;
        return 0;
    }
}

int main(void){
    unko=0;
    int N,A,B;
    scanf("%d %d %d",&N,&A,&B);
    if(A+B>N+1)printf("-1");
    else{
        int gensyo=0;
        for(int i=1;;i++){
            for(int j=N-A*i+1;j<=N-A*(i-1);j++){if(write(N,j)==1)return 0;}//printf("%d ",j);//TODO
            gensyo++;
            if(N-i*A>=B-gensyo&&N-(i+1)*A<B-(gensyo+1)){
                int leng=N-i*A-(B-gensyo-1);
                for(int j=N-i*A-leng+1;j<=N-i*A;j++){if(write(N,j)==1)return 0;}
                for(int j=N-i*A-leng;j>=1;j--){if(write(N,j)==1)return 0;}
                break;
            }
        }
    }
    write(N,0);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N,&A,&B);
     ^