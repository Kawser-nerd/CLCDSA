#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>

using namespace std;


int main(){
    cin.tie(0);
    
    long long N; cin >> N;
    long long a;
    for (long long i = 1; i * i <= N; i++){
        if (N%i == 0) a = i;
    }
    long long b = N/a;
    int ans = 0;
    while (b){
        b /= 10;
        ans++;
    }
    cout << ans << endl;
}