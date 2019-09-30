#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,l[1000001]={},r[1000002]={},sum[1000001],n,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        l[a]++;
        r[b+1]++;
    }
    sum[0]=l[0];
    ans=sum[0];
    for(int i=1;i<=1000000;i++){
        sum[i]=sum[i-1]+l[i]-r[i];
        ans=max(sum[i],ans);
    }
    printf("%d\n",ans);
}