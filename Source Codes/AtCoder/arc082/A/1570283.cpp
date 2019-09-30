#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        std::cin >> x;

    sort(a.begin(), a.end());
    int cmax = 0;
    for(int i = 0, s = -1; i < n; i++) {
        if (s == a[i]) continue;
        s = a[i];
        int c = 1;
        for(int j = i + 1; j < n && a[j] <= a[i] + 2; j++) {
            c++;
        }
        cmax = max(cmax, c);
    }
    cout << cmax << endl;

    return 0;
}