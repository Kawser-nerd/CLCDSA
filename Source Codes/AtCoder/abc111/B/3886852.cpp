#include <iostream>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    for(int i = n; i <= 999; i++) {
        string si = to_string(i);
        if(si[0] == si[1] && si[1] == si[2]) {
            cout << si << endl;
			break;
        }
    }
}