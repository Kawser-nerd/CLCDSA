#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int a, b, c, k; cin >> a >> b >> c >> k;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end(), greater<char>());
    
    cout << pow(2, k) * v[0] + v[1] + v[2] << endl;        
    return 0;
}