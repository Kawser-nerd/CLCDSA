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
#include <cctype>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    string s;
    cin >> s;
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++){
        if (i == 0){
            if (s[i] != 'A'){
                ok = false;
            }
        } else if (2 <= i && i <= (int)s.size() - 2){
            if (s[i] == 'C'){
                cnt++;
            } else {
                if (!islower(s[i])){
                    ok = false;
                }
            }
        } else {
            if (!islower(s[i])){
                ok = false;
            }
        }
    }
    if (cnt != 1){
        ok = false;
    }
    if (ok){
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }






    return 0;
}