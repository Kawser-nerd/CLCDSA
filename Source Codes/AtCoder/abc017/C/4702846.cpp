#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int x[100002]={},sum[100002]={},n,m,l,r,s,ans,y=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&l,&r,&s);
        x[l]+=s;
        x[r+1]-=s;
        y+=s;
    }
    ans=y;
    for(int i=1;i<=m;i++){
        sum[i]=sum[i-1]+x[i];
        ans=min(ans,sum[i]);
    }
    printf("%d\n",y-ans);
}