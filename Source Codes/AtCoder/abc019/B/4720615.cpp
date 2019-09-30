#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int cnt=0,n;
    char s[1001],c;
    c='A';
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<=n;i++){
        if(i==n||c!=s[i]){
            if(cnt){
                printf("%c%d",c,cnt);
            }
            cnt=1;
            c=s[i];
        }
        else{
            cnt++;
        }
    }
    printf("\n");
}