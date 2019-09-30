#include <iostream>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    if(a[n]!=2) return !printf("-1\n");

    LL L=2,R=3;
    for(int i=n-1;i>=1;i--){
        if(R/a[i] == (L-1)/a[i]) return !printf("-1\n");
        L = ((L-1)/a[i]+1)*a[i];
        R = (R/a[i]+1)*a[i] - 1;
    }
    printf("%lld %lld\n", L,R);
}