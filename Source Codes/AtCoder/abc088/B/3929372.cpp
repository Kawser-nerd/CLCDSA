#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, alice_p = 0, bob_p = 0;

int main() {
    cin >> n;
    vector<int> card(n);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    sort(card.begin(), card.end(), greater<int>());
    for (int j = 0; j < n; j++) {
        if (j % 2) {
            bob_p += card[j];
        } else {
            alice_p += card[j];
        }
    }
    cout << alice_p - bob_p << endl;
    return 0;
}