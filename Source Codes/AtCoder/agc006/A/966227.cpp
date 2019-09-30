#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    int n;
    string s,t;

    cin >> n >> s >> t;

    for(int l = n; l <= 2*n; l++) {
        bool flag = false;
        for(int i = 0; i < 2*n-l; i++){
            if(s[n-1-i] != t[2*n-l-1-i]){
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << l << endl;
            return 0;
        }
    }

    cout << 2 * n << endl;

    return 0;
}