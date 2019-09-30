#include <iostream>
#include <vector>
#define all(v) v.begin(), v.end()
#define loop(n) for(size_t i=0; i<n; ++i)
using namespace std;
int main(){
    size_t n;cin >> n;
    vector<string> v(n);
    loop(n) cin>>v[i];
    reverse(all(v));
    loop(n){
        for(auto&& e : v)
            cout << e[i];
        cout << endl;
    }
}