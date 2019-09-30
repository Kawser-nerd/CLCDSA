#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int main(){
    string s;
	cin >> s;
    int ans = -1;
    char prev = 0;
    for(char c : s){
        if(c != prev){
            prev = c;
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
}