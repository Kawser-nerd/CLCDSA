#include <cstdio>
#include <cstring>
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

string solve()
{
    int n, R, P, S;
    scanf("%d%d%d%d", &n, &R, &P, &S);
    string answer = "IMPOSSIBLE";
    update(answer, construct(n, 'R'), R, P, S);
    update(answer, construct(n, 'P'), R, P, S);
    update(answer, construct(n, 'S'), R, P, S);
    return answer;
}

int main()
{
    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        printf("Case #%d: %s\n", test, solve().c_str());
    }
    return 0;
}
