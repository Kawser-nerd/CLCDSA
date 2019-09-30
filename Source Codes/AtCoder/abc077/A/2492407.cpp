#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s2.begin(), s2.end());
    if (s1 == s2) printf("YES\n");
    else printf("NO\n");
    return 0;
}