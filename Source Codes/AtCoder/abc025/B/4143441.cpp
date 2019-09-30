#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int N, A, B;
    cin >> N >> A >> B;

    int e = 0;
    int w = 0;
    for(int i = 0; i < N; ++i)
    {
        string si;
        int di;
        cin >> si >> di;

        if(di < A)
            di = A;
        else if(di > B)
            di = B;

        if(si[0] == 'E')
            e += di;
        else
            w += di;
    }
    if(e == w)
        cout << 0 << endl;
    else if(e > w)
        cout << "East " << e - w << endl;
    else
        cout << "West " << w - e << endl;
    return 0;
}