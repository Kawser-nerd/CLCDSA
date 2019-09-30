#include<stdio.h>

int main(void)
{
        int i,n1,n2;
        char o[51],e[51];

        scanf("%s",o);
        scanf("%s",e);

        n1 = 0;
        n2 = 0;
        while(o[n1]!='\0')
                n1++;
        while(e[n2]!='\0')
                n2++;

        if(n1>n2){
                for(i=0;i<n2;i++)
                        printf("%c%c",o[i],e[i]);
                printf("%c",o[n1-1]);
        }
        else{
                for(i=0;i<n1;i++)
                        printf("%c%c",o[i],e[i]);
        }
        printf("\n");

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",o);
         ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",e);
         ^