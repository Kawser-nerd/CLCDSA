#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int r, c, w;
        cin >> r >> c >> w;

        cout << "Case #" << tt << ": " << r * (c / w) + w - 1 + (c % w > 0) << endl;
    }

    return 0;
}
