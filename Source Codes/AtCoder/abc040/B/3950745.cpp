#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define MMP(a, b, c) make_pair(make_pair(a, b), c)
#define MAX 1000000000
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        int s = sqrt(i);
        for(int j=s; j>=1; j--){
            if(i%j == 0){
                ans = min(ans, abs(i/j-j)+n-i);
            }
        }
    }
    cout << ans << endl;

    return 0;
}