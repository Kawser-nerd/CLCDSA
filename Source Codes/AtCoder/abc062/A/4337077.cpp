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
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int x,y;
    cin >> x >> y;
    vector<int> group2 = {4,6,9,11};
    vector<int> group1 = {1,3,5,7,8,10,12};
    string ans;
    if (x == 2 && y == 2) {
        ans = "Yes";
    } else if (find(all(group2),x) != group2.end() && find(all(group2),y) != group2.end()){
        ans = "Yes";
    } else if (find(all(group1),x) != group1.end() && find(all(group1),y) != group1.end()){
        ans = "Yes";
    } else {
        ans = "No";
    }
    cout << ans << endl;


    return 0;
}