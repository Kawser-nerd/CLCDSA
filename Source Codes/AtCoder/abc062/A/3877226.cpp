#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int x, y;
    cin >> x >> y;

    vector<int> g0 = {1, 3, 5, 7, 8, 10, 12};
    vector<int> g1 = {4, 6, 9, 11};

    string ans;
    if(x == 2 || y == 2)
        ans = "No";
    else if((g0.end() != find(g0.begin(), g0.end(), x)) && (g0.end() != find(g0.begin(), g0.end(), y)))
        ans = "Yes";
    else if((g1.end() != find(g1.begin(), g1.end(), x)) && (g1.end() != find(g1.begin(), g1.end(), y)))
        ans = "Yes";
    else
        ans = "No";

    cout << ans << endl;
    return 0;
}