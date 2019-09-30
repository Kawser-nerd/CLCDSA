#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int max = *max_element(a.begin(), a.end());
    int min = *min_element(a.begin(), a.end());

    cout << max - min << endl;
    return 0;
}