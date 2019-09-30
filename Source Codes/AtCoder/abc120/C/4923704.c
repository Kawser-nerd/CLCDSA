#include <stdio.h>

int main(void)
{

        char S[100000];

        int n,a=0,b=0,i,s;

        scanf("%s",&S);
        n=strlen(S);
        for(i=0;i<n;i++){
                if(S[i]=='0')a++;
                else if(S[i]=='1')b++;
        }
        if(a>b)s=b*2;
        else s=a*2;

        printf("%d\n",s);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100000]’ [-Wformat=]
         scanf("%s",&S);
               ^
./Main.c:11:11: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
         n=strlen(S);
           ^
./Main.c:11:11: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:11:11: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",&S);
         ^