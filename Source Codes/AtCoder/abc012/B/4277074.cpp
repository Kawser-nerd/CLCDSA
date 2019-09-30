#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <ios>
#include <iomanip>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int N;
    cin >> N;
    int h = N / 3600;
    N %= 3600;
    int m = N / 60;
    N %= 60;
    int s = N;

    cout << setfill('0') << right << setw(2) << h;
    cout << ':' << setfill('0') << right << setw(2) << m;
    cout << ':' << setfill('0') << right << setw(2) << s << endl;;

    return 0;
}