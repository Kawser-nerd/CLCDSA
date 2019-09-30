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
    int a,b;
    cin >> a >> b;
    if((a*b)%2==0){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;


    return 0;
}