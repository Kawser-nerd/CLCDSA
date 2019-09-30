#include <stdio.h>

int main()
{   int n,i;
    scanf("%d",&n);
    int b[101],j;
    b[n]=0;
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    
    int l=n;
    int op[100],k=0,flag=1;
    while(flag>0&&n>=0){
        flag=0;
        for(i=n-1;i>=0;i--){
            if(b[i]==i+1){
                op[k]=b[i];
                k++;
                flag=1;
                for(j=i;j<n-1;j++){
                    b[j]=b[j+1];
                }
                n--;
                break;
            }
        }
    }
    if(k<l){
        printf("-1");
        return 0;
    }
    for(i=k-1;i>=0;i--){
    printf("%d\n",op[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&b[i]);
         ^