#include<stdio.h>

int main(){
    int a=0, c=0, small=1;
    int len, cNum = 0;
    char s[10];
    scanf("%s", s);

    for(len=0; s[len]!='\0'; len++);

    if(s[0] == 'A') a=1;
    for(int i=2; i<len-1; i++){
        if(s[i] == 'C'){
            if(cNum != 0){
                c = 0;
                break;
            } 
            c = 1;
            cNum = i;
        }
    }
    for(int i=1; i<len; i++){
        if(i == cNum) continue;
        if(s[i]<'a' || 'z'<s[i]){
            small=0;
            break;
        }
    }
    if(a==1 && c==1 && small==1) printf("AC");
    else printf("WA");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^