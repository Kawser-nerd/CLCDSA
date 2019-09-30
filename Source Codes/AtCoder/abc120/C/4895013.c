#include<stdio.h>
#include<string.h>


int main()
{
        char s[100000];
        scanf("%s",&s);

        int n=strlen(s);

        int count1=0,count0=0;

        int i;
        for(i=0; i<n; i++){
                if(s[i] == '1') count1++;
                else count0++;
        }

        int youjo;
        if(count1 < count0) youjo=count1;
        else youjo=count0;

        printf("%d\n",youjo*2);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100000]’ [-Wformat=]
         scanf("%s",&s);
               ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",&s);
         ^