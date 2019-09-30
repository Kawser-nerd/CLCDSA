#include <stdio.h>

int main()
{   
    int n,m;
    scanf("%d%d",&n,&m);
    int flag[100000]={1},number[100000]={0};
    for(int i=0;i<n;i++){
        number[i]++;
        //printf("num%d=%d\n",i,number[i]);
    }
    int x[m],y[m];
    for(int i=0;i<m;i++){
        scanf("%d%d",&x[i],&y[i]);
        number[(x[i]-1)]--;
        if(flag[(x[i]-1)]==1){
            flag[(y[i]-1)]=1;
        }
        if(number[(x[i]-1)]==0){
            flag[(x[i]-1)]=0;
        }
        number[(y[i]-1)]++;
        
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //printf("number%d=%d flag%d=%d\n",i,number[i],i,flag[i]);
        if(flag[i]==1)ans++;
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&x[i],&y[i]);
         ^