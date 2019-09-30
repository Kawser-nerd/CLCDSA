#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    char s[15];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(i==0&&s[i]<='z'&&s[i]>='a'){
            s[i]+='A'-'a';
        }
        if(i&&s[i]>='A'&&s[i]<='Z'){
            s[i]-='A';
            s[i]+='a';
        }
    }
    printf("%s\n",s);
}