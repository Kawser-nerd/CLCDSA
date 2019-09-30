# include <iostream>
# include <vector>
using namespace std;


vector<char> acids = {'A', 'T', 'G', 'C'};


bool is_acid(const char c) {
    return find(acids.begin(), acids.end(), c) == acids.end();
}


int main() {
    string s; cin >> s;
    int ans = 0;
    int crt = 0;

    for (char c: s) {
        if (is_acid(c)) {
            crt = 0;
        }
        else {
            crt++;
            ans = max(ans, crt);
        }
    }

    cout << ans << endl;
    return 0;
}