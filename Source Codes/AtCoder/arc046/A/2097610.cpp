#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    int n;
    cin >> n;

    int a = n % 9 == 0 ? 9 : n % 9;
    for(int i = 0; i <= (n-1) / 9;  i++){
        cout << a;
    }
    cout << endl;

    return 0;
}