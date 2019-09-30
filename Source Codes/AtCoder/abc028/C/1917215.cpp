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
    vector<int> a(5);
    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }

    vector<int> sum;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            for(int k = j + 1; k < 5; k++){
                sum.push_back(a[i] + a[j] + a[k]);
            }
        }
    }

    sort(sum.begin(), sum.end(), std::greater<int>());

    cout << sum[2] << endl;
    return 0;
}