#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    int length = s.size() - 1;
    while (length > 0) {
        string sub = s.substr(0, length);
        if (length % 2 == 0) {
            int mid = length / 2;
            if (sub.substr(0, mid) == sub.substr(mid, mid)) {
                ans = length;
                break;
            }
        }
        length--;
    }
    cout << ans << endl;
}