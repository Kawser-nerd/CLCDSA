#include <iostream>
#include <vector>
using namespace std;

vector<long long> layer = {1}, patty = {1};

long long getPatty(int n, long long x) {
    if (n == 0) {
        return (x == 1 ? 1 : 0);
    } else {
        if (x <= layer[n - 1] + 1) {
            return getPatty(n - 1, x - 1);
        } else if (x <= 2 * layer[n - 1] + 2) {
            return patty[n - 1] + 1 + getPatty(n - 1, x - (layer[n - 1] + 2));
        } else {
            return 2 * patty[n - 1] + 1;
        }
    }
}

int main() {
    int N;
    long long X;
    cin >> N >> X;

    for (int i = 1; i <= N; i++) {
        layer.push_back(2 * layer[i - 1] + 3);
        patty.push_back(2 * patty[i - 1] + 1);
    }
  
    cout << getPatty(N, X) << endl;
}