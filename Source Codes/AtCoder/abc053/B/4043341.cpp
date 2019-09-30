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
    string s;
    cin >> s;
    int in1 = -1,in2 = -1;
    for (int i = 0; i < (int)s.size(); i++){
        if (in1 == -1 && s[i] == 'A'){
            in1 = i;
        }
        if (s[i] == 'Z'){
            in2 = i;
        }
    }

    cout << in2 - in1 + 1 << endl;





    return 0;
}