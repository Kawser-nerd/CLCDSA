#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <algorithm>  // std::copy()
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
#include <numeric>  // accumulate(ALL(vec), 0)  0 ????
#include <cmath>
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define DESCEND greater<int>()  // sort ?? ????
#define UNIQUE(vec) (vec).erase(unique(ALL((vec))), (vec).end());  // ??sort???????
#define MIN(vec) min_element(ALL((vec)))  // ?????????????????? * ???????
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0)  // 0 ????
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1?vec2?????? vec2???????????
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007


int main() {
    cin.tie();
    ios::sync_with_stdio(false);

    // input
    string S, front, back;
    cin >> S;
    
    // calculation
    bool flag = true;
    size_t len = S.length();
    while (flag) {
        S.pop_back();
        S.pop_back();
        len = S.length();
        front = S.substr(0, len/2);
        back = S.substr(len/2, len/2);
        if (front == back) {
            flag = false;
        }
    }
    cout << len << "\n";
    
    return 0;
}