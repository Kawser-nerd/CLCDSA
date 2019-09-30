#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,a=0,b=0,c=0;
    char S[3];
    scanf("%s",&S);
    for(int i=0;i<3;i++){
        if(S[i]=='a'){
            a++;
        }else if(S[i]=='b'){
            b++;
        }else if(S[i]=='c'){
            c++;
        }
    }

    if((a==1)&&(b==1)&&(c==1)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[3]’ [-Wformat=]
     scanf("%s",&S);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&S);
     ^