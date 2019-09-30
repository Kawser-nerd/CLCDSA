#include <stdio.h>
#include <math.h>
int main(){
    char n[10];
    int i;
    while((n[i]=getchar())!='\n')
    i++;
    if(n[0] == 'a'&&n[1]=='\n'){
        printf("-1\n");
    }
    else{
        printf("a\n");
    }
    return 0;
}