#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    char s[120],c[27]="abcdefghijklmnopqrstuvwxyz";
    scanf("%s",s);
    int tmp,count,ans=1e9;
    for (int i=0; i<26; i++){
        count=0;
        tmp=0;
        for (int j=0; j<strlen(s); j++){
            if (s[strlen(s)-1-j]==c[i]){
                if(tmp<count){
                    tmp=count;
                }
                count=0;
            } else {
                count++;
            }
        }
        if(tmp<count){
            tmp=count;
        }
        if(tmp<ans){
            ans=tmp;
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^