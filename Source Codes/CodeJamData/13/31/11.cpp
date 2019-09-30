#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 1000010
char s[SIZE];
int L,tt,st[SIZE];
bool vow(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main(){
    int T,n,i,j,cs=0;
    scanf("%d",&T);
    while(T--){
        long long an=0;
        tt++;
        scanf("%s%d",s,&n);
        L=strlen(s);
        for(i=0;i<L;i=j){
            if(!vow(s[i])){
                if(n==1)st[i]=tt;
                for(j=i+1;j<L&&!vow(s[j]);j++){
                    if(j-n+1>=i)st[j-n+1]=tt;
                }
            }
            else j=i+1;
        }
        for(i=0,j=0;i<L;i++){
            while(j<L&&(j<i||st[j]!=tt))j++;
            //printf("[%d,%d]\n",i,j);
            an+=max(0,L-(j+n)+1);
        }
        printf("Case #%d: %lld\n",++cs,an);
    }
    return 0;
}
