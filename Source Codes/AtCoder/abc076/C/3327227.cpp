#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

string S, T;

bool check(int index) {
    for (int i = 1; i < T.size(); ++i) if (S[i + index] != T[i] && S[i + index] != '?') return false;
    return true;
}

int main() {
    cin >> S >> T;

    int index = -1;
    for (int i = S.size() - T.size(); i >= 0; --i) {
        if ((S[i] == T[0] || S[i] == '?') && check(i)) {
            index = i;
            break;
        }
    }    

    if (index == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;

    } else {
        for (int i = 0; i < S.size(); ++i) {
            if (index <= i && i < index + T.size()) cout << T[i - index];
            else                                    cout << (S[i] == '?' ? 'a' : S[i]);
        }
        cout << endl;
    }

    return 0;
}