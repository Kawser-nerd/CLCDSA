#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <algorithm>  // std::copy()
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
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
    string str, alpha;
    cin >> str;
    for (char i = 'a'; i <= 'z'; ++i) {
        alpha += i;
    }
    
    // calculation
    size_t s_len = str.length();
    bool flag = false;
    char res = 'a';
    REP(i, alpha.length()) {
        char ch = alpha[i];
        if ((int)str.find(ch) == -1) {
            res = ch;
            flag = true;
            break;
        }
    }
    
    if (flag) {
        cout << res << "\n";
    } else {
        cout << "None" << "\n";
    }
    
    return 0;
}