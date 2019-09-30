#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=n-2;i>=0;i--){
        if(a[i]!=a[n-1]){
            printf("%d\n",a[i]);
            return 0;
        }
    }
}