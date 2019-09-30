#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    if (s < t) printf("Yes\n");
    else printf("No\n");
    return 0;
}