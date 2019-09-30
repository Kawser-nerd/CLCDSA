using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <iostream>
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
    int N;
    cin >> N;
    vector<char> s(N);
    char key[4] = {'P','W','G','Y'};
    map<char,int> m;
    m.insert(make_pair('P',0));
    m.insert(make_pair('W',0));
    m.insert(make_pair('G',0));
    m.insert(make_pair('Y',0));

    for (int i = 0; i < N; i++){
        cin >> s[i];
        m.at(s[i])++;
    }

    bool ok = true;
    for (int i = 0; i < 4; i++){
        if (m.at(key[i]) == 0){
            ok = false;
        }
    }
    if (ok) {
        cout << "Four" << endl;
    } else {
        cout << "Three" << endl;
    }

    return 0;
} ./Main.cpp:1:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.