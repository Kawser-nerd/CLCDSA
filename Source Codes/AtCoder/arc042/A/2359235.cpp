#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    int n, m;
    scanf("%d %d", &n, &m);

    vector<bool> threads(100001);
    fill(threads.begin(), threads.end(), false);

    vector<int> input(100001);
    for (int i = 0; i < m; i++) {
        scanf("%d", &input[i]);
    }
    for (int i = m - 1; i >= 0; i--) {
        if (!threads[input[i]]) {
            printf("%d\n", input[i]);
            threads[input[i]] = true;
        }
    }

    vector<int> rest;
    for (int i = 1; i <= n; i++) {
        if (!threads[i]) {
            rest.push_back(i);
        }
    }
    sort(rest.begin(), rest.end());
    for (int i = 0; i < rest.size(); i++) {
        printf("%d\n", rest[i]);
    }

    return 0;
}