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

    //substr(x,y)
    //index = x<=x+y-1
    int ans = 0;
    for (int i = 1; i < (int)s.size(); i++){
        string ss = s.substr(0,(int)s.size()-i);
        int size = (int)ss.size();
        if (size % 2 == 0){
            string s1 = ss.substr(0,size/2);
            string s2 = ss.substr(size/2);
            if (s1 == s2){
                ans = size;
                break;
            }
        }
    }
    cout << ans << endl;
                


    return 0;
}