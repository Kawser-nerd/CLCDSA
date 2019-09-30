#include <stdio.h>
int main(void){
    int n;
    int c[100]={0};
    int count=0;
    int max=-1, min=101;
    
    
    scanf("%d", &n);
    for(int i=0; i<n; i++)scanf("%1d", &c[i]);
    
    for(int i=1; i<=4; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(c[j]==i)count++;    
        }
        if(count>=max)max=count;
        if(count<=min)min=count;
        count=0;
    }
    
    printf("%d %d\n", max, min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:27: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0; i<n; i++)scanf("%1d", &c[i]);
                           ^