#include<stdio.h>
    #include<string.h>
    int main(void){

        int A,i;
    double B,C,D,E,N,M,x,y,j,cou=0,cou2,v[1000000],w[1000000],min_i,en=0.0;
        char S[100][100],W[100],s[10],X,Y;
    scanf("%d",&A);
    for(i=0;i<A;i++){
        scanf("%lf %s",&v[i],&S[i]);
        if(S[i][0]=='B'){
            en+=v[i]*380000.0;
        }else{
            en+=v[i];
        }
    }
    printf("%f",en);
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:10:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100]’ [-Wformat=]
         scanf("%lf %s",&v[i],&S[i]);
               ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf %s",&v[i],&S[i]);
         ^