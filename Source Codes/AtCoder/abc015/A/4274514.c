#include <stdio.h>

int main(){
    char a[50],b[50];
    int alen=0,blen=0;
    scanf("%s %s",&a,&b);
    for (int i=0;i<50;i++){
        if (a[i]!='\0'){
            alen++;
        }
        else{
            break;
        }
        if (b[i]!='\0'){
            blen++;
        }
        else{
            break;
        }
    }
    if (alen>blen){
        printf("%s",a);
    }
    else{
        printf("%s",b);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
     scanf("%s %s",&a,&b);
           ^
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[50]’ [-Wformat=]
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s",&a,&b);
     ^