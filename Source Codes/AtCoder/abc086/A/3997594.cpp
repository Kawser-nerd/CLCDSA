#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if(a * b % 2 == 0)
	    cout << "Even" << "\n";
    else
        cout << "Odd" << "\n";
}