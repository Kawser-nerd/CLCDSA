#include <stdio.h>
int main(void){
    char s[11] = {}, t[11] = {};
    scanf("%s %s", s, t);
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == '@'){
            if(t[i] == 'a' || t[i] == 't' || t[i] == 'c' || t[i] == 'o' || t[i] == 'd' || t[i] == 'e' || t[i] == 'r' || t[i] == '@'){
            }else{
                puts("You will lose");
                break;
            }
        }else if(t[i] == '@'){
            if(s[i] == 'a' || s[i] == 't' || s[i] == 'c' || s[i] == 'o' || s[i] == 'd' || s[i] == 'e' || s[i] == 'r' || s[i] == '@'){
            }else{
                puts("You will lose");
                break;
            }
        }else if(s[i] != t[i]){
            puts("You will lose");
            break;
        }
        i ++;
    }
    if(s[i] == '\0'){
        puts("You can win");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s", s, t);
     ^