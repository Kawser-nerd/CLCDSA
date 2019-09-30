/*~~~~~~~~~~~~~~~~~ K++ code ~~~~~~~~~~~~~~~~~~~
in(n, t)
kluster<int ,int> klst <<
for(i, n){
    int p, q ;
    cin >> p >> q ;
    push(klst, (q, p))
}
sort(klst, 1)
for(i, n){
    if(klst[i][0]<=t) out(klst[i][1]); return 0
}
out("TLE")
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct struct_0_ {;
    int m_0;
    int m_1;
};
bool comp_klst_(const struct_0_& a, const struct_0_& b){;
    if(a.m_0 != b.m_0){;
        return (a.m_0 < b.m_0);
    };
    if(a.m_1 != b.m_1){;
        return (a.m_1 < b.m_1);
    };
    return (1);
};
bool comp_klst_0_(const struct_0_& a, const struct_0_& b){;
    return (a.m_0 < b.m_0);
};
bool comp_klst_1_(const struct_0_& a, const struct_0_& b){;
    return (a.m_1 < b.m_1);
};
;;;
;
int main(){
  ;;;
    int n, t;
    cin >> n >> t;
    ;
    vector<struct_0_> klst;;
    for(int i = 0; i <  n; ++i){;;;;
        int p, q ;;
        cin >> p >> q ;;
        klst.push_back({q, p});
    ;};;;
    sort(klst.begin(), klst.end(), comp_klst_1_);;
    for(int i = 0; i <  n; ++i){;;;;
        if(klst[i].m_0<=t) {;;cout << (klst[i].m_1) << endl;; return (0);;};
    ;};;;
    cout << ("TLE") << endl;;
    ;
}