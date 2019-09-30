#include<stdio.h>
    #include<string.h>
    int main(void){
            int b=0,r=0,i,n;
            char s[100000];
            scanf("%s",&s);
            n=strlen(s);
            for(i=0;i<n;i++){
                    if(s[i]==0x30) r++;
                    else b++;}
            if(r>=b) printf("%d",2*b);
            else printf("%d",2*r);
            return 0;
    } ./Main.c: In function ‘main’:
./Main.c:6:19: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100000]’ [-Wformat=]
             scanf("%s",&s);
                   ^
./Main.c:6:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%s",&s);
             ^