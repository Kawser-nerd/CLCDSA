#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n, a;
    cin >> n >> a;
    int amari = n % 500;
    if(a >= amari) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}