#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    cout << min(b / a, c) << endl;
}