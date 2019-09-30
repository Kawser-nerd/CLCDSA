#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int H, W;
    cin >> H >> W;
    vector<string> v(H);
    for(auto& e : v)
        cin >> e;
    for(auto& e : v)
    {
        cout << e << endl;
        cout << e << endl;
    }
    return 0;
}