#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    string line;
    vector<int> c(5, 0);

    cin >> N;
    cin >> line;

    for (int i = 0; i < N; i++) c[line[i] - '0']++;

    auto min = min_element(c.begin() + 1, c.end());
    auto max = max_element(c.begin() + 1, c.end());

    cout << *max << " " << *min << endl;
}