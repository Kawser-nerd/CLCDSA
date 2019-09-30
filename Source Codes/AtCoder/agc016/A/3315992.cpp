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
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //?????(???????1???)
        x = (x * x) % MOD;
        n >>= 1; //????(n = n >> 1)
    }
    return res;
}


int main(){
    cin.tie(0);
    
    string s; cin >> s;
    int ans = s.length() - 1;
    for (int i = 1; i < s.length(); i++){
        if (s[i] != s[i-1]) break;
        else if (i == s.length() - 1){
            ans = 0;
            cout << ans << endl;
            return 0;
        }
    }

    for (int i = 0; i < 26; i++){
        int select = 'a' + i;
        string tmp = s;
        for (int j = 1; j < s.length(); j++){
            for (int k = 0; k < s.length() - j; k++){
                tmp[k] = tmp[k];
                if (tmp[k+1] == select) tmp[k] = tmp[k+1];
            }
            for (int k = 0; k < s.length() - j; k++){
                if (tmp[k] != select) break;
                else if (k == s.length() - j - 1){
                    ans = min(ans, j);
                    j = s.length();
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}