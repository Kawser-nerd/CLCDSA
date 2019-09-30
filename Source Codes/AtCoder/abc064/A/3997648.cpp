#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int r, g, b;
    cin >> r >> g >> b;
    int keta = r * 100 + g * 10 + b;
    if(keta % 4 == 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}