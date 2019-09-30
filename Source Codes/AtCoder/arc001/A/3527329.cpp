#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string answers;
    vector<int> sums{0,0,0,0};

    cin >> n;
    cin >> answers;

    for (int i = 0; i < answers.size(); i++) {
        int selection = answers[i] - '0';
        sums[selection-1] = sums[selection-1] + 1;
    }

    cout << *max_element(sums.begin(), sums.end()) << " " << *min_element(sums.begin(), sums.end()) << endl;

    return 0;
}