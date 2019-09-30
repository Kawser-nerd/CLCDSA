#include<cstdio>
using namespace std;
int main(){
    int n,ans=0,a[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<=a[i];j++){
            if((a[i]-j)%2==1&&(a[i]-j)%3!=2){
                ans+=j;
                break;
            }
        }
    }
    printf("%d\n",ans);
}