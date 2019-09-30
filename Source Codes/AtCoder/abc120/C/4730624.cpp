#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <string>

typedef long long ll;


using namespace std;
int main() {
    string s;
    cin >> s;
    ll o,z;
    for (auto c:s){
        if(c=='1'){o++;}else{z++;}
    }
    cout << min(o,z)*2 << endl;
    return 0;
}