#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

typedef pair <int, int> pii;
typedef pair <string, string> pss;
typedef long long ll;

const int inf = 1e9 + 1;
const double eps = 1e-9;
const int MAXN = 18;

int n;
string s;
map <pss, int> m;
ll sol;

int main(){

    cin >> n;
    cin >> s;

    for (int mask = 0; mask < (1<<n); mask++){
        string r = "", b = "";
        for (int i = 0; i < n; i++){
            if (mask & (1<<i)) r += s[i];
            else b += s[i];
        }
        reverse(b.begin(), b.end());
        m[mp(r, b)]++;
    }

    for (int mask = 0; mask < (1<<n); mask++){
        string r = "", b = "";
        for (int i = 0; i < n; i++){
            if (mask & (1<<i)) r += s[n+i];
            else b += s[n+i];
        }
        reverse(b.begin(), b.end());
        sol += m[mp(b, r)];
    }

    cout << sol;

    return 0;

}