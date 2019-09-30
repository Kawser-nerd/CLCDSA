#include <iostream>

using namespace std;
int main(void) {
    int n;
    cin >> n;
    int max = 0, sum = 0;;
    for(int i = 0 ; i < n ; ++i) {
        int l;
        cin >> l;
        sum += l;
        if (max < l) {
            max = l;
        }
    }
    sum -= max;
    cout << (max < sum ? "Yes" : "No") << endl;

    return 0;
}