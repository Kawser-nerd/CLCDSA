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
    long a,b,c;
    cin >> a >> b >> c;

    if (a*b*c%2==0) {
        cout << 0 << endl;
    } else {
        cout << (a<b ? a* (b<c? b : c) : b* (a<c? a : c)) << endl;
    }
}