#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, count{};
    vector<int> a;
    bool done;
    cin >> N;
    
    for (int i {0}; i < N; i++) {
        int A{};
        cin >> A;
        a.push_back(A);
    }
    
    for (int j {1}; j < N; j++) {
        int pre_val = a.at(j-1);
        if (pre_val == a.at(j) && !done) {
            count++;
            done = true;
        } else {
            done = false;
        }
    }
    cout << count << endl;
    
    return 0;
}