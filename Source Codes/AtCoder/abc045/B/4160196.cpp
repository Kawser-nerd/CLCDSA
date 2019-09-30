#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;

int main() {
    string A, B, C;
    cin >> A >> B >> C;

    char turn = 'a';
    int apos = 0, bpos = 0, cpos = 0;
    while (true) {
        switch (turn) {
            case 'a':
                if (apos == A.size()) {
                    cout << "A" << endl;
                    return 0;
                }
                turn = A[apos++];
                break;
            case 'b':
                if (bpos == B.size()) {
                    cout << "B" << endl;
                    return 0;
                }
                turn = B[bpos++];
                break;
            case 'c':
                if (cpos == C.size()) {
                    cout << "C" << endl;
                    return 0;
                }
                turn = C[cpos++];
                break;
        }
    }
}