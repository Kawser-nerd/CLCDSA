#include <stdio.h>
int main(void){
    int h,w,n;
    scanf("%d%d%d",&w,&h,&n);
    int square[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            square[i][j] = 1;
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        int a,b,c,d,e,f,g;
        scanf("%d%d%d",&a,&b,&c);
        switch(c)
        {
            case 1:
                d=0;e=h;f=0;g=a;
            break;
            
            case 2:
                d=0;e=h;f=a;g=w;
            break;
            
            case 3:
                d=0;e=b;f=0;g=w;
            break;
            
            case 4:
                d=b;e=h;f=0;g=w;
            break;
        }
        
        for(int j=d;j<e;j++)
        {
            for(int k=f;k<g;k++)
            {
                square[j][k] = 0;
            }
        }
    }
    
    
    
    int ans = 0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            ans += square[i][j];
        }
    }
    
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&w,&h,&n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a,&b,&c);
         ^