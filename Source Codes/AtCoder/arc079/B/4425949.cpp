#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ll k;
    cin >> k;

    cout << "50\n";
    ll c = k/50;
    ll d = k%50;
    for (int i = 0; i < d; i++) {
        cout << 49 + c + 51 - d << " ";
    }
    for (int i = d; i < 50; i++) {
        cout << 49 + c - d << " ";
    }
    return 0;
}