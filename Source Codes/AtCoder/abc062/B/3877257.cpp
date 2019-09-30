#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int H, W;
    cin >> H >> W;

    vector<string> v(H);
    for(auto& e : v)
        cin >> e;

    for(int i = 0; i < W + 2; ++i)
        cout << '#';
    cout << endl;

    for(auto& e : v)
    {
        cout << '#' << e << '#' << endl;
    }

    for(int i = 0; i < W + 2; ++i)
        cout << '#';
    cout << endl;

    return 0;
}