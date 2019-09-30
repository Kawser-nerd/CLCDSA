#include <iostream>
#include <bitset>
using namespace std;
const int N=4000000+10;
bitset<N> B;
int n,a[N];
int main(){
    B[0]=1;
    scanf("%d",&n); int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); sum+=a[i];
        B=B|(B<<a[i]);
    }   
    int x=(sum+1)/2;
    while(B[x]==0) x++;
    printf("%d\n", x);
}