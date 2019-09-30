#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
template <class... T> void printArr(T&&...){ }
#endif

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> vs(n);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        vs[a]++;
        vs[b]++;
    }
    for(int i=0;i<n;i++){
        if(vs[i] & 1){
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}