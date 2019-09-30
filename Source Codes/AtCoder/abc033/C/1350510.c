#include <stdio.h>
int main(void){
    // Here your code !
    char a[1000000];
    for(int k =0;k<1000000;k++){
        a[k]='e';
    }
    int c0=0,x =0;
    scanf("%s",&a);
    for(int i =0; i<1000000 ; i++){
        if(a[i]=='+'||a[i]=='e'){
            if(c0!=0){
                c0 = 0;
            }
            else{
                x++;
            }
        }
        if(a[i]=='0'){
            c0 = 1;
        }
        if(a[i]=='e'){
            break;
        }
    }
    printf("%d\n",x);
} ./Main.c: In function ‘main’:
./Main.c:10:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[1000000]’ [-Wformat=]
     scanf("%s",&a);
           ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&a);
     ^