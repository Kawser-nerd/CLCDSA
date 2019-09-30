#include <stdio.h>

int main() {
    long whites = 0,i = 0,ans = 0;
    char s;

    //input
    while ((s = getchar()) != '\n') {
        if(s == 'W'){
            ans += i;
            whites ++;
        }

        i++;
    }

    //calculation
    for(i = 1; i <= whites ; i++){
        ans -= (i - 1);
    }

    //Output
    printf("\n%ld\n",ans);

    return 0;
}