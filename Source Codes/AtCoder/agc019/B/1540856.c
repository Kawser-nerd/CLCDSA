#include <stdio.h>
int main(void){
    char po;
    int buri[26]={};
    int mojisu=0;
    long long int ans=1;
    while(scanf("%c",&po)!=-1&&po-'a'>=0&&po-'a'<26){
        mojisu++;
        buri[po-'a']++;
        ans+=(long long int)(mojisu-buri[po-'a']);
    }
    printf("%lld",ans);
    return 0;
}