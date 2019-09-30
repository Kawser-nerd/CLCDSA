#include <iostream>
#include <vector>

using namespace std;

int main() {

    int B[10], C[10];

    for (int i = 0; i < 10; i++) {
        int b;
        cin >> b;
        B[i] = b;
        C[b] = i;
    }

    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++) {
        string a, b = "";
        cin >> a;
        for (int j = 0; j < a.length(); j++) {
            b += C[a[j] - '0'] + '0';
        }
        v.push_back(stoi(b));

    }

    sort(v.begin(), v.end());

    for (int b:v) {
        string a = "", b_ = to_string(b);
        for (int i = 0; i < b_.length(); i++) {
            a += B[b_[i] - '0'] + '0';
        }
        cout << a << endl;
    }
}