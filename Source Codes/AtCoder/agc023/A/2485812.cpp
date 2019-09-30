#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200000+10;
int n;
LL a[N];
map<LL, int> mp;

int main() {
    scanf("%d",&n);

    LL s = 0;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        s += a[i]; mp[s] ++;
    }
    LL ret=0;
    s=0; mp[0]++;
    for(int i=1;i<=n;i++) {
        mp[s]--;
        ret+=mp[s];
        s+=a[i];
    }
    cout<<ret<<endl;

}