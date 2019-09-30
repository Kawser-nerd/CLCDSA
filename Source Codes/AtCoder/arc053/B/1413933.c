#include <string.h>
#include <stdio.h>
int main(void){
    char s[100000];
    int a[26]={0};
    int cnt=0,ans;
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0;i<len;i++){
        a[s[i]-'a']++;
    }
    //????
    for(i=0;i<26;i++){
        if(a[i]%2!=0)cnt++;
    }
    if(cnt==0){
        ans=len;
    }else{
        ans=2*((len-cnt)/(2*cnt))+1;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^