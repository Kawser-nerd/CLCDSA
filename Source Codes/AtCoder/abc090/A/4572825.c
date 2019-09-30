#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2,v[1000000],w[1000000],min_i,en=0;
        char S[100][100],W[100],s[10],X,Y;
       for(i=0;i<3;i++){
            scanf("%s",&S[i]);
    }
    printf("%c%c%c",S[0][0],S[1][1],S[2][2]);
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:7:19: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
             scanf("%s",&S[i]);
                   ^
./Main.c:7:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%s",&S[i]);
             ^