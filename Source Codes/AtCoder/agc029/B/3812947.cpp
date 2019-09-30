#include <iostream>
#include <set>

using namespace std;

#define MAX_N 200005
int A[MAX_N];
multiset<int> inverted;

int invert(int x) {
    int inv{1};
    while (inv <= x) inv <<= 1;
    return inv - x;
}

int main() {
    int N; scanf("%d", &N);
    for (int i{}; i < N; ++i) scanf("%d", &A[i]);
    sort(A, A + N);

    int count{};
    for (int i{N-1}; i >= 0; --i) {
        if (inverted.count(A[i])) {
            ++count;
            inverted.erase(inverted.find(A[i]));
        } else {
            inverted.insert(invert(A[i]));
        }
    }

    printf("%d\n", count);
    return 0;
}