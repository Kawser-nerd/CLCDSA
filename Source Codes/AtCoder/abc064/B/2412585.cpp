#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N;
    vector<int> l;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        l.push_back(n);
    }
    sort(l.begin(), l.end(), greater<int>());
    cout << l.front() - l.back() << endl;
}