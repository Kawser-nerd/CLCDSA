#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <cassert>

#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef unsigned long ul;
typedef pair<ul, ul> P;

int main() {
    char s[1001];
    int x=0;
    map<char, int> mp;
    mp['N']=0; mp['W']=1; mp['S']=2; mp['E']=3;

    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++) {
        x = x | (1 << mp[s[i]]);
    }
    if (x==5 || x==10 || x==15) cout << "Yes" << endl;
    else cout << "No" << endl;
}