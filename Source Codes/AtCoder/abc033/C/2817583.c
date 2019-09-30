#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void){
    char s[100200];
    scanf("%s",s);
    int ans=0;
    bool zero=false;
    if (strlen(s)==1 && s[0]!='0'){
        ans++;
    }
    
    for (int i=0; i<strlen(s); i++){
        if (s[i]=='+'){
            if(i==1 && s[0]!='0'){
                ans++;  
            } else if (s[i-2]=='+' && s[i-1]!='0'){
                ans++;
            }
            if (i==strlen(s)-2 && s[i+1]!='0'){
                ans++;
            }
        } else if (s[i]=='*'){
            if (i==strlen(s)-2){
                if(zero==false && s[i-1]!='0' && s[i+1]!='0'){
                    ans++;
                }
            } else if (s[i+2]=='+' && zero==false && s[i-1]!='0' && s[i+1]!='0'){
                ans++;
            } else if (s[i+2]=='+'){
                zero=false;
            } else if (s[i-1]=='0'){
                zero=true;
            }
        }
    }    
    printf ("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^