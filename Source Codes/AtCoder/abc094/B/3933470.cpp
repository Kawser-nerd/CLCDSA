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
    int N,M,X;
    cin >> N >> M >> X;
    vector<int> a(M);
    int left = 0;
    int right = 0;
    for (int i = 0; i < M; i++){
        cin >> a[i];
        if (a[i] < X) {
            left++;
        } else {
            right++;
        }
    }
    cout << min(left,right) << endl;


    return 0;
}