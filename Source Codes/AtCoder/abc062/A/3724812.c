#include<stdio.h>

int main(void)
{
        int x,y;

        scanf("%d%d",&x,&y);

        if(x==2 || y==2)
                printf("No\n");
        else if(x==1 || x==3 || x==5 || x==7 || x==8 || x==10 || x==12){
                if(y==4 || y==6 || y==9 || y==11)
                        printf("No\n");
                else
                       printf("Yes\n");
        }
        else{
                if(y==4 || y==6 || y==9 || y==11)
                        printf("Yes\n");
                else
                        printf("No\n");
        }

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&x,&y);
         ^