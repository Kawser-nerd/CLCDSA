#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a[3],x[101]={},ans[4];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    x[a[0]]=1;
    x[a[1]]=2;
    x[a[2]]=3;
    sort(a,a+3);
    for(int i=0;i<3;i++){
        ans[x[a[i]]]=3-i;
    }
    for(int i=1;i<=3;i++){
        printf("%d\n",ans[i]);
    }
}