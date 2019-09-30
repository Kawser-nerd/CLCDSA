#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long kk;
char s[1000];
int main(){
        scanf("%s",s);
        scanf("%lld",&kk);
        n=strlen(s);
        for(int i=0;i<n;i++){
                if(s[i]>'1') return printf("%c",s[i]),0;
                else kk--;
                if(kk==0) return printf("%c",s[i]),0;
        }
}