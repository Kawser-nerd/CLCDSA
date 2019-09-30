#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )

int A[3];
int main() {
    cin >> A[0] >> A[1] >> A[2];
    std::sort(A, A+3);
    int c = (A[1] - A[0]) / 2;
    if ((A[1] - A[0]) % 2) {
        c++;
        A[2] += 1;
    }
    cout << c + (A[2] - A[1]) << endl;
}