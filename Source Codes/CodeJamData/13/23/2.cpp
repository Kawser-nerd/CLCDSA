#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

set<string> dict;
vector<string> wlist;

template<typename T> int size(const T &a) { return a.size(); } 

int memo[5000][10];
string str;

int go(int a, int dist) {
    if(a == size(str)) {
        return 0;
    }

    if(memo[a][dist] != -1) return memo[a][dist];
    string tt = str.substr(a);

    int ret = -2;
    for(int i=0;i<size(wlist);i++) {
        const string &w = wlist[i];
        if(size(w) > size(tt)) continue;

        int tmp = 0;
        int dd = dist;
        for(int j=0;j<size(w);j++) {
            if(tt[j] != w[j]) {
                tmp++;
                if(dd) {
                    dd = -1; break;
                } else {
                    dd = 5;
                }
            }
            if(dd) dd--;
        }
        if(dd == -1) continue;

        int tmp2 = go(a + size(w), dd);
        if(tmp2 < 0) continue;

        tmp += tmp2;
        if(ret == -2 || ret > tmp) ret = tmp;
    }
    return memo[a][dist] = ret;
}

void process(void) {
    memset(memo, -1, sizeof(memo));
    cin >> str;
    cout << go(0, 0) << endl;
}

int main(void)
{
    ifstream fin("garbled_email_dictionary.txt");
    string str;
    while(fin >> str) {
        wlist.pb(str);
    }
    dict = set<string>(wlist.begin(), wlist.end());

    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
