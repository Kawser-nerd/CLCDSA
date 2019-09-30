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
    vector<int> a;
    int w;
    for(int i=0;i<3;i++){
        cin >> w;
        a.push_back(w);
    }
    sort(a.begin(),a.end());
    cout << a[2]*10+a[1]+a[0] << endl;


    return 0;
}