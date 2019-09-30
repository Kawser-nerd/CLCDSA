#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
int main(){
    string s1;
    string s2;
    cin >> n >> s1 >> s2;

    long long ans;
    int i;
    if (s1[0] == s2[0]) {ans = 3; i = 1;} else {ans = 6; i = 2;}
    bool lastv = s1[0] == s2[0] ? true : false; 
    for (; i < n; ++i) {
        if (s1[i] == s2[i]) {
            if (lastv) ans *= 2;
            lastv = true;
        } else {
            if (lastv) ans *= 2;
            else ans *= 3;
            i++;
            lastv = false;
        }
        ans %= 1000000007LL;
    }
    cout << ans << endl;
}