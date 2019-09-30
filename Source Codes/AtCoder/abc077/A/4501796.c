#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,D,E,x,y,cou=0,v[3];
    char S[3],s[3],X,Y;
    scanf("%s%s",&S,&s);
   if((S[0]==s[2])&&(S[1]==s[1])&&(S[2]==s[0])){
            printf("YES");
    }else{
        printf("NO");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[3]’ [-Wformat=]
     scanf("%s%s",&S,&s);
           ^
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[3]’ [-Wformat=]
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",&S,&s);
     ^