#include <stdio.h>
#include <string.h>
int main(void)
{

        char k[100000];
        scanf("%s",&k);

        int n = strlen(k);
        int a=0,b=0;
        int i,m;

        for(i=0;i<n;i++){
        if (k[i]=='0') a++;
        else if(k[i]=='1') b++;
        }

        m=a;
        if (a>b) m=b;

        printf("%d\n",2*m);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100000]’ [-Wformat=]
         scanf("%s",&k);
               ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",&k);
         ^