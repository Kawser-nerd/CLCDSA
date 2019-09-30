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

    if(n == 1){
        cout << "Not Prime" << endl;
        return 0;
    }

    if(n == 2 || n == 3 || n == 5){
        cout << "Prime" << endl;
        return 0;
    }

    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0){
        cout << "Not Prime" << endl;
        return 0;
    }

    cout << "Prime" << endl;

    return 0;
}