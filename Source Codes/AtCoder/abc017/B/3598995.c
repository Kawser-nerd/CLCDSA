#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[55];
    scanf("%s",str);
    int jg=1;
    int ct=strlen(str)-1;
    while(ct>=0){
        if(str[ct]=='o' || str[ct]=='k' || str[ct]=='u'){
            ct--;
        }
        else if(str[ct]=='h'){
            if(ct==0) jg=-1;
            else if(str[ct-1]=='c'){
                ct-=2;
            }
            else jg=-1;
        }
        else jg=-1;
        if(jg==-1) break;
    }
    if(jg==1) printf("YES\n");
    else printf("NO\n");
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str);
     ^