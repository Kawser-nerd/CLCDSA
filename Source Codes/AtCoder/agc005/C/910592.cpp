class _in{struct my_iterator{int it;const bool rev;explicit constexpr my_iterator(int it_, bool rev=false):it(it_),rev(rev){}constexpr int operator*(){return it;}constexpr bool operator!=(my_iterator& r){return it!=r.it;}void operator++(){rev?--it:++it;}};const my_iterator i,n;public:explicit constexpr _in(int n):i(0),n(n){}explicit constexpr _in(int i,int n):i(i,n<i),n(n){}constexpr const my_iterator& begin(){return i;}constexpr const my_iterator& end(){return n;}};
 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
using i64 = long long;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int& x : a) cin >> x;

    int dia = *max_element(a.begin(), a.end());
    bool ok = true;
    ok &= dia >= (N == 2 ? 1 : 2);
    vector<int> cnt(N, 0);
    for(int x : a) cnt[x]++;

    for(int i : _in(dia + 1))
        ok &= --cnt[dia - i / 2] >= 0;
    for(int i : _in(N))
        if(cnt[i] > 0)
            ok &= i >= (dia + 1) / 2 + 1;

    cout << (ok ? "Possible" : "Impossible") << endl;
    
                         
}