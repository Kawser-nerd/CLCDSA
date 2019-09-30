#include <stdio.h>
#include <string.h>
#include<math.h>

int main(){
    char strings[40] = "";
    char new[40] = "";
    char *Pnew = new;

    int i, k = 0;

    fgets(strings, 40, stdin);
    strings[strlen(strings)-1] = '\0';

    for(i = 0; i < strlen(strings); i++){
        if('a' == strings[i]){
            continue;
        }else if(strings[i] == 'i'){
            continue;
        }else if(strings[i] == 'u'){
            continue;
        }else if(strings[i] == 'e'){
            continue;
        }else if(strings[i] == 'o'){
            continue;
        }
        *(Pnew+k) = strings[i];
        k++;
    }
    strings[strlen(strings)-1] = '\0';

    printf("%s\n", Pnew);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(strings, 40, stdin);
     ^