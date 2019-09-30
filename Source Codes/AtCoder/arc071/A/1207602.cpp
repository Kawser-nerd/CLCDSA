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
#endif

int main(){
    int n; cin >> n;
    vector<map<char, int>> vm(n);
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(char c : s){
            vm[i][c]++;
        }
    }
    for(char c='a';c<='z';c++){
        int num = M;
        for(int i=0;i<n;i++){
            num = min(num, vm[i][c]);
        }
        for(int i=0;i<num;i++){
            cout << c;
        }
    }
    cout << '\n';
    return 0;
}