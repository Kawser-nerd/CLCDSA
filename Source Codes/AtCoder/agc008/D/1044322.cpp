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
#include"basic.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
#endif

// int as[510 * 510];
vector<int> as(510 * 510);
// vector<int> as(10 * 10);
int main(){
    int n; cin >> n;
    vector<int> xs(n), xs2;
    for(int i=0;i<n;i++){
        cin >> xs[i];
        as[xs[i] - 1] = i + 1;
    }
    xs2 = xs;
    sort(xs2.begin(), xs2.end());
    vector<int> spaces;
    int prev = 0;
    for(int i=0;i<n;i++){
        spaces.push_back(xs2[i] - prev - 1);
        prev = xs2[i];
    }
    prints("as", as);
    prints("spaces", spaces);
    int acc = 0, idx = 0, idx2 = -1;
    queue<int> q;
    for(int i=0;i<n;i++){
        idx2 += spaces[i] + 1;
        int num = as[idx2];//as[xs[i] - 1];//i + 1;//xs[i];
        acc += spaces[i];
        acc -= num - 1;
        prints("acc", acc, "num", num, "idx2", idx2);
        if(acc < 0){
            cout << "No" << '\n';
            return 0;
        }
        for(int rem = num - 1; rem; rem--){
            while(as[idx]){ idx++; }
            as[idx] = num;
        }
        for(int rem = n - num, idx3 = idx2 + 1; rem; rem--){
            // while(as[idx3]){ idx3++; if(idx3 >= as.size()){ cout << "No" << '\n'; return 0; }}
            // as[idx3] = num;
            q.push(num);
        }
    }
    for(int i=0;i<n*n;i++){
        if(!as[i]){
            as[i] = q.front(); q.pop();
        }
    }
    for(int i=0;i<n*n;i++){
        if(!as[i]){
            cout << "No" << '\n';
            return 0;
        }
    }
    prints("as", as);
    vector<int> nums(n);
    for(int i=0;i<n*n;i++){
        nums[as[i] - 1]++;
        if(nums[as[i] - 1] == as[i]){
            prints(as[i], i + 1);
            // prints(i + 1, xs[as[i] - 1]);
            if(i + 1 != xs[as[i] - 1]){
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i] != n){
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
    for(int i=0;i<n * n;i++){
        cout << as[i] << (i == n * n - 1 ? '\n' : ' ');
    }
    return 0;
}