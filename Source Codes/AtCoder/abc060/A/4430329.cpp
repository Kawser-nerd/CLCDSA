#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
#define LL long long 
char d[105][105];

int main(){
    string a,b,c;
    LL H, W;
    LL ans = 1e18;
    cin >> a >> b >> c;
    if(a[a.size()-1] == b[0] && b[b.size()-1] == c[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}