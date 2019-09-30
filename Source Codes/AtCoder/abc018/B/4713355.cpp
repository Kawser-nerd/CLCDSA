#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,l,r,m;
    char s[101],t[101];
    scanf("%s",s);
    m=strlen(s);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&l,&r);
        strcpy(t,s);
        for(int j=l-1;j<r;j++){
            s[j]=t[r-1-j+l-1];
        }
    }
    printf("%s\n",s);
}