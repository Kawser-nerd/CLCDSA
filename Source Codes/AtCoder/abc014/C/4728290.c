#include <stdio.h>
int main()
{   int n;
    scanf("%d",&n);
    int a[n],b[n];
    int table[1000002]={0};
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        table[a[i]]++;
        table[b[i]+1]--;
    }
    int imoz[1000002]={0};
    imoz[0]=table[0];
    int max=imoz[0];
    for(int i=1;i<1000002;i++){
        imoz[i]=imoz[i-1]+table[i];
        if(imoz[i]>max){
            max=imoz[i];
        }
    }
    printf("%d\n",max);
    
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a[i],&b[i]);
         ^