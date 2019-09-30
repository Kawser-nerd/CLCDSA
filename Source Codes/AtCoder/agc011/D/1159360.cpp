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
    // chrono::steady_clock clk;
    // auto start = clk.now();
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<int> ss(n);
    for(int i=0;i<n;i++){
        ss[i] = s[i] == 'A';
    }
    bool flip = false, fflip = false;;
    int idx = 0;
    for(int i=0;i<k;i++){
        if(flip ^ ss[idx]){
            // ss[idx] = !ss[idx];
            ss[idx] ^= 1;
        }else{
            // flip = !flip;
            flip ^= 1;
            idx++;
            if(idx == n){ idx = 0; }
        }
        // if(i % 1000000 == 0 && clk.now() - start > 1900ms){
        //     if(n % 2 && (k - i - 1) % 2){
        //         fflip = true;
        //     }
        //     break;
        // }
    }
    cout << (fflip ^ flip ^ ss[idx] ? 'A' : 'B');
    for(int i=1;i<n;i++){
        cout << (flip ^ ss[(idx + i) % n] ? 'A' : 'B');
    }
    cout << '\n';
    return 0;
}