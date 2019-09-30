#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

using ll = long long;

int main() {
    string s;
    
    cin >> s;
    
    cout << min(count(s.begin(), s.end(), '0'), count(s.begin(), s.end(), '1')) * 2 << endl;
}