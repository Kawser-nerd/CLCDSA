#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string X;
    int s, t, l, ans;
    s = 0;
    t = 0;
    cin >> X;
    l = X.length();
    ans = l;
    for(int i=0; i<l; ++i){
        if(X[i] == 'S'){
            s++;
        }
        else if(X[i] == 'T'){
            ans -= (s > 0) ? 2 : 0;
            s -= (s > 0) ? 1 : 0;
        }
    }
    cout << ans << endl;
}