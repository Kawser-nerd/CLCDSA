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

struct struct_0_ {;;;
    int m_0;;
    int m_1;;
};;;
bool comp_klst_(const struct_0_& a, const struct_0_& b){;;;
    if(a.m_0 != b.m_0){;;;;
        return (a.m_0 < b.m_0);;
    };;;;
    if(a.m_1 != b.m_1){;;;;
        return (a.m_1 < b.m_1);;
    };;;;
    return (1);;
};;;
bool comp_klst_0_(const struct_0_& a, const struct_0_& b){;;;
    return (a.m_0 < b.m_0);;
};;;
bool comp_klst_1_(const struct_0_& a, const struct_0_& b){;;;
    return (a.m_1 < b.m_1);;
};;;
;;

int main(){
  ;;
    int n, m;
    cin >> n >> m;
    ;
    vector<struct_0_> klst;;
    for(int i = 0; i <  m; ++i){;;;
        int a, b;
    cin >> a >> b;
    ;
        klst.push_back({a, b});
    };;;
    sort(klst.begin(), klst.end(), comp_klst_1_);;
    int ans = 0;;
    int i = 0;;
    int cut = klst[0].m_1-1;;
    while(i<klst.size()){;;;
        if(klst[i].m_0<=cut) {;++i; continue;}
        else {;++ans; cut = klst[i].m_1-1;};
    };;;
    cout << (ans+1) << endl;;
}