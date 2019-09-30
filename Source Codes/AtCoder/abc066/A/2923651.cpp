#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vs;
    int a, b, c; cin >> a >> b >> c;
    vs.push_back(a);
    vs.push_back(b);
    vs.push_back(c);

    sort(vs.begin(), vs.end());

    cout << vs[0] + vs[1] << endl;

    return 0;
}