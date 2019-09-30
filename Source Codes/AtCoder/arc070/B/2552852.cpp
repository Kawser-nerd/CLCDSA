#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
bool c[5050];
void make(){
    c[0] = true;
    for(int i=1;i<5050;i++) c[i] = false;
}
void orc(int a){
    bool t[5050];
    for(int i=0; i<5050;i++) t[i] = c[i];
    for(int i=0; i<5050-a; i++) if(i+a < 5050) c[i+a] |= t[i];
}

int main(){
    ll n,k,sum=0;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){cin >> a[i]; sum += a[i];}
    if(sum < k){cout << n << endl; return 0;}
    sort(a.begin(),a.end());
    if(a[0]>=k){cout << 0 << endl; return 0;}
    int ok = 0, ng = n;
    
    while(1 < ng - ok){
        int i = (ng + ok) / 2 - 1;
        if(i<0) i = 0;
        make();
        for(int j=0;j<n;j++){
            if(! (a[j] >= k || j==i)){
                orc(a[j]);
            }
        }
        bool flag = true;
        for(int j=k-a[i];j<k;j++) if(c[j]==1){
                flag = false;
                break;
        }
        if(flag){
            ok = i+1;
        }
        else{
            ng = i+1;
        }
    }

    cout << ok << endl;
    return 0;
}