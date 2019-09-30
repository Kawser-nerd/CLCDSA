#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int A,B,K;
    cin >> A >> B >> K;
    vector<int> ans;
    for (int i = A; i <= B; i++){
        if (i < A+K){
            ans.push_back(i);
        } else if (i > B-K){
            ans.push_back(i);
        }
    }
    for (int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << endl;
    }


    return 0;
}