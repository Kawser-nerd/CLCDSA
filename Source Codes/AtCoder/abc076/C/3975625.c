#include <string.h>
#include <stdio.h>

int main()
{
    char s[51],t[51];
    scanf("%s%s",s,t);
    int ls=strlen(s),lt=strlen(t);
    if(ls<lt){
        printf("UNRESTORABLE");
        return 0;
    }
    for(int i=ls-lt;i>=0;i--){
        int k=0;
        for(int j=i;j<=i+lt;j++){
            if(s[j]!='?'&&s[j]!=t[k]){
                break;
            }else{
                k++;
                if(k==lt){
                    int m;
                    for(m=0;m<i;m++){
                        if(s[m]=='?'){
                            printf("a");
                        }else{
                            printf("%c",s[m]);
                        }
                    }
                    printf("%s",t);
                for(m=i+lt;m<ls;m++){
                        if(s[m]=='?'){
                            printf("a");
                        }else{
                            printf("%c",s[m]);
                        }
                    }    
                    return 0;
                }
            }
        }
    }
    printf("UNRESTORABLE");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s",s,t);
     ^