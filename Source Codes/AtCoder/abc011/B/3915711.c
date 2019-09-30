#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char a[12];
    int i = 0;
    while((a[i] = getchar())!='\n'){
        i++;
    }
    if(a[0]>'Z'){
        a[0]=a[0]-'a'+'A';
    }
    for(int j = 1;j < i;j++){
        if(a[j]<'a'){
            a[j]= a[j]-'A'+'a';
        }
    }
    for(int j = 0;j<i;j++){
        printf("%c",a[j]);
    }
    printf("\n");
    return 0;
}