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

int para;


int input(int n){
    cout << n << endl;
    string s;
    cin >> s;
    if (s == "Male") return 0;
    if (s == "Female") return 1;
    
    exit(0);
}

int main(){
    //cin.tie(0);

    Int x, y; cin >> x >> y;
    Int X = x;
    Int Y = y;
    

    while (1){
        Int tmp;
        if (X >= 2){
            tmp = X/2;
            X %= 2;
            Y += tmp;
            y += tmp;
        }else if (Y >= 2){
            tmp = Y/2;
            Y %= 2;
            X += tmp;
            x += tmp;
        }else{
            break;
        }
    }
    x -= x%2;
    y -= y%2;

    if (x == y) cout << "Brown" << endl;
    else cout << "Alice" << endl;
}