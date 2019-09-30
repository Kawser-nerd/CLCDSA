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

int n, a, b;;
;;
bool func(int i){;;
int sum = 0;;
    while(i){;;;
        sum += i%10;
        i = i/10;
    };;;
    if((a<=sum&&sum<=b)) {;return (true);}
    else {;return (false);};
};;;

int main(){
  ;;
    cin >> n >> a >> b;
    ;
    int ans = 0;;
    if(1<n){;
        for(int i = 1; i <= n; ++i){;;;
        if(func(i)) {;ans += i;};
    }
    ;}
    else {;
        for(int i = 1; i >= n; --i){;;;
        if(func(i)) {;ans += i;};
    }
    ;};;;;
    cout << (ans) << endl;;
    return (0);
    ;
    ;
}