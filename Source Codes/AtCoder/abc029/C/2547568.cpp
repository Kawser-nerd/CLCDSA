#include <iostream>
#include <string>

using namespace std;
int N;

void solve(string s) {
    if (s.length() == N) {
        cout << s << endl;
        return;
    }
    solve(s + 'a');
    solve(s + 'b');
    solve(s + 'c');
    return;
}

int main() {
    cin >> N;
    solve("");
}