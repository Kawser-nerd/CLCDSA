#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
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
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    int n; cin >> n;
    vector<int> ss(n);
    int mini = 1000;
    for(int i = 0; i < n; i++){
        cin >> ss[i];
        if(ss[i] % 10){
            mini = min(mini, ss[i]);
        }
    }
    int sum = accumulate(ss.begin(), ss.end(), 0);
    if(sum % 10 == 0){
        cout << (mini != 1000 ? sum - mini : 0) << '\n';
    }else{
        cout << sum << '\n';
    }
    return 0;
}