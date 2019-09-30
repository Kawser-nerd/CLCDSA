#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> strings(N);
    for(int i = 0; i < N; i++) {
        cin >> strings[i];
    }
    sort(strings.begin(), strings.end());
    for(string str: strings)
        cout << str;
    cout << endl;
    return 0;
}