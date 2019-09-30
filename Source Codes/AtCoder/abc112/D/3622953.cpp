#include <cstdio>
#include <vector>
using namespace std;

vector<long long int> divisor(long long int m) {
    vector<long long int> divs;
    for (long long int i = 1; i*i <= m; i++) {
        if (m % i == 0) {
            divs.push_back(i);
            if (m != i*i) {
                divs.push_back(m / i);
            }
        }
    }
    sort(divs.begin(), divs.end());

    return divs;
}

int main() {
    long long int n, m;

    scanf("%lld%lld", &n, &m);
    vector<long long int> divs = divisor(m);

    for (long long int i = divs.size()-1; i >= 0; i--) {
        if (divs[i] * n <= m) {
            printf("%lld\n", divs[i]);
            break;
        }
    }
    return 0;
}