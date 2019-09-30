#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, c;
    int ans;
    cin >> a >> b >> c;

    set<int> s;

    s.insert(a);
    s.insert(b);
    s.insert(c);

    cout << s.size() << endl;

}