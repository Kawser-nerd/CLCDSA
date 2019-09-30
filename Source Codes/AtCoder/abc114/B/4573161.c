#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B,C,D,E,N,M,x,y,i,j,cou=0,cou2=99999999,v[1000000],w[1000000],min_i,en=0;
        char S[100],W[100],s[10],X,Y;
    scanf("%s",&S);
    A=strlen(S);
    for(i=0;i<A-2;i++){
        cou=(S[i]-48)*100+(S[i+1]-48)*10+S[i+2]-48;
        if(cou<753){
        if((753-cou)<cou2){
            cou2=753-cou;
        }}else{
            if((cou-753)<cou2){
            cou2=cou-753;
        }
        }
    }
    printf("%d",cou2);
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
     scanf("%s",&S);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&S);
     ^