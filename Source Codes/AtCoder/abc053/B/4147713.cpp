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


char A[55][55];
char B[55][55];

ull E = 1000000007;

int main() {
    string S;
    cin >> S;
    size_t apos = S.find('A');
    size_t zpos = S.rfind('Z');
    cout << S.substr(apos, zpos - apos + 1).size() << endl;
}