#include <string.h>
#include <stdio.h>

int main()
{   char s[27];
    scanf("%s",s);
    int l=strlen(s),alp[26]={0};
    if(strcmp(s,"zyxwvutsrqponmlkjihgfedcba")==0){
        printf("-1");
        return 0;
    }
    
    if(l<26){
    for(int i=0;i<l;i++){
        alp[s[i]-'a']++;
        }
        printf("%s",s);
        for(int i=0;i<26;i++){
            if(alp[i]==0){
                printf("%c",'a'+i);
                return 0;
            }
        }
    }
    int p;
    for(int i=25;i>0;i--){
        if(s[i]-'a'>s[i-1]-'a'){
            p=i-1;
            break;
        }
    }
    for(int i=0;i<p;i++){
        alp[s[i]-'a']++;
        printf("%c",s[i]);
    }
    for(int i=0;i<26;i++){
        if(alp[i]==0&&s[p]-'a'<i){
            printf("%c",'a'+i);
            return 0;
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^