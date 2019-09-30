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
    map<char,int> cnt;
    for (char i = 'A'; i <= 'F'; i++){
        cnt.insert(make_pair(i,0));
    }

    for (int i = 0; i < (int)s.size(); i++){
        cnt[s[i]]++;
    }

    for (int i = 'A'; i <= 'F'; i++){
        cout << cnt.at(i);
        if (i != 'F'){
            cout << ' ';
        } else {
            cout << endl;
        }
    }


    return 0;
}