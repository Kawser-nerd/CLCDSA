#include<stdio.h>
#include<string.h>

int main(void)
{
    int a=0,b=0,c,d,i,l;
    char n[99999];

    scanf("%s",n);
    l=strlen(n);
    for(i=0;i<l;i++){
          if(n[i]=='0') a=a+1;
     else if(n[i]=='1') b=b+1;
     }
     if(a>b) c=b;
     else c=a;
     d=c*2;
     printf("%d\n",d);
     return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",n);
     ^