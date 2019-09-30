#include <iostream>
#include <string>
#include <map>
using namespace std;

int getGCD(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    return (a % b == 0 ? b : getGCD(b, a % b));
}

long long getLCD(int a, int b) {
    return (long long)(a / getGCD(a, b)) * b;
}

int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    long long L = getLCD(N, M);
    map<long long, char> mp;
    for (int i = 0; i < N; i++) mp[i * (L / N)] = S[i];
    for (int i = 0; i < M; i++) {
        if (mp.find(i * (L / M)) != mp.end() && mp[i * (L / M)] != T[i]) {
            L = -1;
            break;
        }
    }

    cout << L << endl;
}