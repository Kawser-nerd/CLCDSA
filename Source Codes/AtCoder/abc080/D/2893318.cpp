#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, c; cin >> n >> c;
    int x = 100100;
    vector<vector<int>> ns(c, vector<int>(x, 0));
    for (int i=0; i<n; i++) {
        int s, t, c; cin >> s >> t >> c;
        ns[c-1][s]++;
        ns[c-1][t]--;
    }

    for (auto &arr: ns)
        for (int i=x-1; i>0; i--)
            if (arr[i-1] < 0) {
                arr[i] += arr[i-1];
                arr[i-1] = 0;
            }

    for (auto &arr: ns) {
        int s = 0;
        for (int i=0; i<x; i++) {
            s += arr[i];
            arr[i] = s;
        }
    }


    vector<int> ms(x, 0);
    for (int i=x-1; i>0; i--)
        for (auto &arr: ns)
            ms[i] += arr[i];

    /*
    for (auto &arr: ns) {
        for (int i=0; i<x; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    for (int i=0; i<x; i++)
        cout << ms[i] << " ";
    cout << endl;
    */
    cout << *max_element(ms.begin(), ms.end()) << endl;
}