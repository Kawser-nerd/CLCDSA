#include<stdio.h>

int main(){
    int i,j,k,N,l;
    scanf("%d",&N);
    int b[101]={0};
    for(i=0;i<N;i++){
        scanf("%d",&b[i]);
    }
    int ans[101]={0};

    int flag=0;
    int bflag=0;
    int out=0;

    for(j=0;j<N&&out==0;j++){
        for(i=0;i<N-j;i++){
            if(b[i]==i+1&&b[i]>ans[j]){
                ans[j]=b[i];
                k=i;
                flag+=1;
            }
        }
        
        if(bflag==flag){
            out=1;
            flag=0;
        }
        
        bflag=flag;
        /*
        printf("j=%d\n",j);
        for(l=0;l<N;l++){
            printf("%d ",b[l]);
        }
        printf("\n");
        */
        for(;k<N;k++){
            b[k]=b[k+1];
        }
        

    }

    if(flag==0){
        printf("-1\n");
    }

    if(flag!=0){
        for(k=0;k<N;k++){
            printf("%d\n",ans[N-k-1]);
        }
    }
    

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&b[i]);
         ^