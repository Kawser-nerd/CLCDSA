#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string construct(int n, char winner)
{
    if (n == 0) {
        string s = "";
        s += winner;
        return s;
    }
    string left = construct(n - 1, winner);
    string right = "";
    if (winner == 'S') {
        right = construct(n - 1, 'P');
    } else if (winner == 'P') {
        right = construct(n - 1, 'R');
    } else {
        right = construct(n - 1, 'S');
    }
    if (left < right) {
        return left + right;
    } else {
        return right + left;
    }
}

void update(string &answer, const string &current, int R, int P, int S)
{
    for (int i = 0; i < current.size(); ++ i) {
        if (current[i] == 'R') {
            -- R;
        } else if (current[i] == 'P') {
            -- P;
        } else if (current[i] == 'S') {
            -- S;
        } else {
            return;
        }
    }
    if (R != 0 || P != 0 || S != 0) {
        return;
    }
    if (answer == "IMPOSSIBLE" || answer > current) {
        answer = current;
    }
}

double calculate(vector<double> a)
{
    vector<vector<double>> f(a.size() + 1, vector<double>(a.size() + 1, 0));
    f[0][0] = 1;
    for (int i = 0; i < a.size(); ++ i) {
        for (int j = 0; j <= i; ++ j) {
            f[i + 1][j] += f[i][j] * (1 - a[i]);
            f[i + 1][j + 1] += f[i][j] * a[i];
        }
    }
    return f[a.size()][a.size() / 2];
}

double solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<double> p(n, 0);
    for (int i = 0; i < n; ++ i) {
        scanf("%lf", &p[i]);
    }
    sort(p.begin(), p.end());

    double answer = 0;
    for (int i = 0; i <= k; ++ i) {
        vector<double> a;
        for (int j = 0; j < i; ++ j) {
            a.push_back(p[j]);
        }
        for (int j = 0; j < k - i; ++ j) {
            a.push_back(p[n - 1 - j]);
        }
        answer = max(answer, calculate(a));
    }
    /*for (int mask = 0; mask < 1 << n; ++ mask) {
        if (__builtin_popcount(mask) == k) {
            vector<double> a;
            for (int i = 0; i < n; ++ i) {
                if (mask >> i & 1) {
                    a.push_back(p[i]);
                }
            }
            answer = max(answer, calculate(a));
        }
    }*/
    return answer;
}

int main()
{
    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        printf("Case #%d: %.10f\n", test, solve());
    }
    return 0;
}
