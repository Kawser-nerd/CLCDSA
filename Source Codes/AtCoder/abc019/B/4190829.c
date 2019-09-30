#include<stdio.h>
#include<string.h>

int main(){
    char s[1001];
    char tmp;
    unsigned int i,count=1;

    scanf("%s",&s);

    tmp = s[0];
    for(i=1;i<=strlen(s);i++){
        if(s[i]==tmp){
            count++;
        }else{  
            printf("%c%d",tmp,count);
            tmp = s[i];
            count = 1;
        }
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[1001]’ [-Wformat=]
     scanf("%s",&s);
           ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s);
     ^