#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int sum = 0, m = 3;
    for (int i = 0; i < 3; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    int k; cin >> k;
    sort(v.begin(), v.end(), greater<char>());

    for (int i = 0; i < m; i++) {
        if (i == 0) {
            sum += pow(2, k) * v[i];
        } else {
            sum += v[i];
        }
    }

    
    cout << sum << endl;        
    return 0;
}