#include <stdio.h>

char str[101];

int getitv(char c){
    int r=0;
    int i,j;
    for(i=0,j=0;str[i]!='\0';i++,j++){
        if(str[i]==c){
            if(j>r)
                r=j;
            j=-1;
        }
    }
    if(j>r)
        return j;
    else
        return r;
}

main(){
    scanf("%s",&str);
    char i;
    int r=1000;

    for(i='a';i<='z';i++){
        if(getitv(i)<r)
            r=getitv(i);
    }
    printf("%d\n",r);
    return 0;
} ./Main.c:21:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:22:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
     scanf("%s",&str);
           ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&str);
     ^