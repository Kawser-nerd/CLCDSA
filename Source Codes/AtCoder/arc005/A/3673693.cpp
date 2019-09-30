#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    const string key1 = "TAKAHASHIKUN";
    const string key2 = "Takahashikun";
    const string key3 = "takahashikun";
    const int key_len = 12;
    int n, l, ans;
    bool b;
    string s;
    cin >> n;
    ans = 0;
    for(int i=0; i<n; ++i){
        cin >> s;
        l = s.length();
        if(i != n-1 && l != key_len){
            continue;
        }
        if(i == n-1 && l != key_len + 1){
            continue;
        }
        b = true;
        if(s[0] == 'T' && s[1] == 'A'){
            for (int j=2; j<key_len; ++j){
                if(s[j] != key1[j]){
                    b = false;
                    break;
                }
            }
        }
        else if(s[0] == 'T' && s[1] == 'a'){
            for (int j=2; j<key_len; ++j){
                if(s[j] != key2[j]){
                    b = false;
                    break;
                }
            }
        }
        else if(s[0] == 't'){
            for (int j=1; j<key_len; ++j){
                if(s[j] != key3[j]){
                    b = false;
                    break;
                }
            }
        }
        else {
            b = false;
        }
        if(b){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}