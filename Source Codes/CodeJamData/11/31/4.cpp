#include <iostream>

using namespace std;

char a[64][64];

int main()
{
    int t;

    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        int n, m;
        cin >> n >> m;

        for (int i=0; i<n; i++)
            cin >> a[i];

        bool f = true;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (a[i][j] == '#')
                {
                    f &= a[i][j+1] == '#' && a[i+1][j] == '#' && a[i+1][j+1] == '#';

                    a[i][j] = '/';
                    a[i][j+1] = '\\';
                    a[i+1][j] = '\\';
                    a[i+1][j+1] = '/';
                }

        cout << "Case #" << tt << ":" << endl;

        if (f)
            for (int i=0; i<n; i++)
                cout << a[i] << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}
