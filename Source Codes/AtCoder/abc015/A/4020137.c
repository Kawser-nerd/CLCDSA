#include <stdio.h>

int main(){
    char a[100];
    char b[100];
    int i = 0;
    while((a[i] = getchar()) != '\n'){
        i++;
    }
    int j = 0;
    while((b[j] = getchar()) != '\n'){
        j++;
    }
    if(i > j){
        for(int k = 0; k <= i; k++){
            printf("%c",a[k]);
        }
    }
    else{
        for(int k = 0; k <= j; k++){
            printf("%c",b[k]);
        }
    }
    return 0;
}