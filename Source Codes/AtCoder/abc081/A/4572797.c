#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
        char S[100],W[100],s[10],X,Y;
       scanf("%s%s%s",&S);
       if(S[0]=='1'){
           cou++;
       }
       if(S[1]=='1'){
           cou++;
       }
       if(S[2]=='1'){
           cou++;
       }
       printf("%d",cou);
       return 0;
    } ./Main.c: In function ‘main’:
./Main.c:6:14: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
        scanf("%s%s%s",&S);
              ^
./Main.c:6:14: warning: format ‘%s’ expects a matching ‘char *’ argument [-Wformat=]
./Main.c:6:14: warning: format ‘%s’ expects a matching ‘char *’ argument [-Wformat=]
./Main.c:6:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%s%s%s",&S);
        ^