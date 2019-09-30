//Coder: Balajiganapathi

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
char b[5][5];

bool hasWon(char p) {   
    bool ok; 
    //row
    fr(i, 4) {
        ok = true;
        fr(j, 4) if(b[i][j] != p && b[i][j] != 'T') ok = false;
        if(ok) return true;
    }
    
    //col
    fr(j, 4) {
        ok = true;
        fr(i, 4) if(b[i][j] != p && b[i][j] != 'T') ok = false;
        if(ok) return true;
    }
    
    //diag
    ok = true;
    fr(i, 4) if(b[i][i] != p && b[i][i] != 'T') ok = false;
    if(ok) return true;
    
    ok = true;
    fr(i, 4) if(b[i][3 - i] != p && b[i][3 - i] != 'T') ok = false;
    if(ok) return true;
    
    return false;
}

int countEmpty() {
    int ret = 0;
    fr(i, 4) fr(j, 4) if(b[i][j] == '.') ++ret;
    
    return ret;
}

int main() {
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("large.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        fr(i, 4) scanf("%s", b[i]);
        string ans;
        if(hasWon('X')) ans = "X won";
        else if(hasWon('O')) ans = "O won";
        else if(countEmpty() == 0) ans = "Draw";
        else ans = "Game has not completed";
        
        printf("Case #%d: %s\n", t, ans.c_str());
    }

	return 0;
}
