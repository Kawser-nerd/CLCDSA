#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cnt++;
            if(cnt == n){
                cout << s[i] << s[j] << endl;
                return 0;
            }
        }
    }

    return 0;
}