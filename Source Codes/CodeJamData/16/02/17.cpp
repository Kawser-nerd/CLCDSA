#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int z = 1; z <= t; z++) {
        string s;
        cin >> s;
        s += "+";

        int ans = 0;
        for (int i = 0; i+1 < s.size(); i++)
            ans += (s[i+1] != s[i]);

        printf("Case #%d: %d\n", z, ans);
    }
}
