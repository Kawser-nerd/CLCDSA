#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

int main(){
    int N = 0;
    cin >> N;
    vector<ull> v;
    for(int i = 0; i < N; ++i){
        ull a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    ull ans = 1;
    int count = 0;
    for(int i = N; i >= 0; --i){
        if(v[i] == v[i-1]){
            ans *= v[i];
            i--;
            count++;
        }
        if(count >= 2) break;
    }
    if(!count) ans = 0;

    cout << ans << endl;
    return 0;
}