#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>

using namespace std;

int main(){
    cin.tie(0);

    long long sx, sy; cin >> sx >> sy;
    long long tx, ty; cin >> tx >> ty;
    long long x = sx;
    long long y = sy;
    
    for (int i = sx; i < tx; i++){
        cout << 'R';
        x++;
    }
    for (int i = sy; i < ty; i++){
        cout << 'U';
        y++;
    }
    for (int i = sx; i < tx; i++){
        cout << 'L';
        x--;
    }
    for (int i = sy; i < ty; i++){
        cout << 'D';
        y--;
    }
    cout << 'D';
    y--;
    for (int i = sx; i < tx; i++){
        cout << 'R';
        x++;
    }
    cout << 'R';
    x++;
    cout << 'U';
    y++;
    for (int i = sy; i < ty; i++){
        cout << 'U';
        y++;
    }
    y++;
    cout << 'L';
    x--;
    cout << 'U';
    y++;
    for (int i = sx; i < tx; i++){
        cout << 'L';
        x--;
    }
    cout << 'L';
    x--;
    cout << 'D';
    y--;
    for (int i = sy; i < ty; i++){
        cout << 'D';
        y--;
    }
    cout << 'R';
    x++;
    cout << endl;
}