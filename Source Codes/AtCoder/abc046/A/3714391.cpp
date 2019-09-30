#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> color;
    for(int i = 0; i < 3; i++) {
        int a; cin >> a;
        color.insert(a);
    }
    cout << color.size() << endl;
}