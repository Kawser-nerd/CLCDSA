#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kmp(char String[],int next[]){
    next[1] = 0;
    int i = 1;
    int j = 0;
    while(i < strlen(String) && j < strlen(String)){
        if(j == 0 || String[i] == String[j]){
        i++;
        j++;
        next[i] = j;

        }else{
            j = next[j];
        }
    }


}


int main()
{
    int next[105];

    char Stringc[105];
    char String[105];

    int i=0;
    int j=0;
    int k=0;

    scanf("%s",Stringc);
    scanf("%s",String);

    int length=strlen(String);
    int lengthc=strlen(Stringc);
    for(i = 0 ; i <= length ; i++){
        next[i] =   0;
    }
    kmp(String , next);

    for(i = 0 ; i < 2*lengthc ; ){
        if(j == length)
            break;
        if(j == 0 || Stringc[i%lengthc] == String[j]){
            j++;
            i++;
        }else{
            j = next[j];
        }
    }
    if(j!=length){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",Stringc);
     ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",String);
     ^