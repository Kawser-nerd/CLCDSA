#include <iostream>
#include <vector>

using namespace std;
int main()
{
    string S;
    cin >> S;
    int n = 0;
    int a[26];
    for (int i=0; i<26; i++) {
        a[i] = 0;
    }
    // ???????
    int p = 0;
    // ??????????
    int q = 0;
    
    long l = S.length();
    for (long i=0; i<l; i++) {
        int x = S[i]- 'a';
        if (a[x] == 0) {
            a[x]++;
        } else {
            a[x] = 0;
            p++;
        }
    }
    for (int i=0; i<26; i++) {
        if (a[i] == 1) {
            q++;
        }
    }
    
    if (q == 0) {
        cout << l << endl;
    } else if (p < q) {
        cout << 1 << endl;
    } else {
        cout << 1 + (p / q) * 2 << endl;
    }
    return 0;
}