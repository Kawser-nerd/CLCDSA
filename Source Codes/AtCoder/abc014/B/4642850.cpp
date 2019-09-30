#include<cstdio>
using namespace std;

int main(){
    int n,x,a[20],ans=0;
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(x&(1<<i)){
            ans+=a[i];
        }
    }
    printf("%d\n",ans);
}