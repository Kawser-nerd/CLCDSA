#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    bool translatable = true;

    vector<char>  c1_to(26, -1);
    vector<char>  c2_to(26, -1);

    for(int i=0; i<S.size(); i++) {
        char c1 = S[i] - 97;
        char c2 = T[i] - 97;

        if(c1_to[c1] >= 0) {
            if(c1_to[c1] != c2) {
                translatable = false;
                break;
            }
        } else {
            c1_to[c1] = c2;
        }

        if(c2_to[c2] >= 0) {
            if(c2_to[c2] != c1) {
                translatable = false;
                break;
            }
        } else {
            c2_to[c2] = c1;
        }
    }

    cout << (translatable ? "Yes" : "No") << endl;
}