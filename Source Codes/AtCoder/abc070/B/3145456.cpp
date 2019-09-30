#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int start = max(a, c);
    int end = min(b, d);

    int duration = end - start;
    cout << (duration < 0 ? 0 : duration) << endl;    

    return 0;
}