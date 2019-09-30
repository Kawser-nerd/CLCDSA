#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int N, L;
    cin >> N >> L;

    vector<string> v(N);
    for(auto& e : v)
        cin >> e;
    
    sort(v.begin(), v.end());

    for(auto& e : v)
        cout << e;
    
    cout << endl;

    return 0;
}