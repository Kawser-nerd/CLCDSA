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

;;
;
long long dp[100];;
;;
;
long long L(int N){;;
    if(dp[N]!=0) {;return (dp[N]);;}
    else {;return (dp[N] = L(N-1)+L(N-2));    ;};
};;
;;

int main(){
  ;;
    dp[0] = 2;;
    dp[1] = 1;;
    int N;
    cin >> N;
    ;
    cout << (L(N)) << endl;;
    ;
    ;
}