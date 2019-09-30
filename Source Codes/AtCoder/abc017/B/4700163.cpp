#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,f[51]={};
    char s[55],c;
    scanf("%s",s);
    n=strlen(s);
    f[0]=1;
    for(int i=0;i<n;i++){
        if(i>=1&&f[i-1]==1&&s[i]=='h'&&s[i-1]=='c'){
            f[i+1]=1;
        }
        if(f[i]==1&&(s[i]=='o'||s[i]=='k'||s[i]=='u')){
            f[i+1]=1;
        }
    }
    if(f[n]){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}