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
    map<char,int> m;
    m['a'] = 0;
    m['b'] = 0;
    m['c'] = 0;
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++){
        m[s[i]]++;
    }
    int n = 0;
    for (char i = 'a'; i <= 'c'; i++){
        if (m[i] == 1) n++;
    }
    if (n == 3){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



    return 0;
}