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
    map<char,int> m;
    for (char i = 'a'; i <= 'z'; i++){
        m[i] = 0;
    }
    for (int i = 0; i < (int)s.size(); i++){
        m[s[i]]++;
    }
    bool ok = true;
    for (char i = 'a'; i <= 'z'; i++){
        if (m[i] >= 2) ok = false;
    }
    if (ok){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }



        


    return 0;
}