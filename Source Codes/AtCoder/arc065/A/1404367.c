#include <string.h>
#include <stdio.h>
#define N 100000
int main(void){
    char s[N];
    int i,miss=0;
    scanf("%s",s);
    int len=strlen(s);
    i=len-1;
    while(i>=0){
        if(s[i]=='m'){
            if(s[i-1]=='a'&&s[i-2]=='e'&&s[i-3]=='r'&&s[i-4]=='d'&&i>=4){
                i-=5;
            }else{
                miss=1;
                break;
            }
        }else if(s[i]=='e'){
            if(s[i-1]=='s'&&s[i-2]=='a'&&s[i-3]=='r'&&s[i-4]=='e'&&i>=4){
                i-=5;
            }else{
                miss=1;
                break;
            }
        }else if(s[i]=='r'){
            if(s[i-1]=='e'&&s[i-2]=='s'&&s[i-3]=='a'&&s[i-4]=='r'&&s[i-5]=='e'&&i>=5){
                i-=6;
            }else if(s[i-1]=='e'&&s[i-2]=='m'&&s[i-3]=='a'&&s[i-4]=='e'&&s[i-5]=='r'&&s[i-6]=='d'&&i>=6){
                i-=7;
            }else {
                miss=1;
                break;
            }
        }else{
            miss=1;
            break;
        }
    }
    if(miss)printf("NO\n");
    else printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^