#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    if(n%k==0){
        cout << 0 << endl;
    }
    else cout << 1 << endl;


    return 0;
}