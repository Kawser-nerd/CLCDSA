#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <assert.h>
using namespace std;

bool check5(int R, int C)
{
    if (R == 1 || R == 2) return false;
    if (R == 3)
    {
        if (C == 5) return false;
        else return true;
    }

    return true;
}

bool check6(int R, int C)
{
    if (R == 1 || R == 2) return false;
    if (R == 3) return false;
    
    return true;
}

bool check(int X, int R, int C)
{
    if (R > C)
    {
        swap(R, C);
    }

    if ((R * C) % X) return false;
    if (C < X) return false;

    if (X == 1) return true;
    if (X == 2) return true;
    if (X == 3)
    {
        if (R == 1) return false;
        else return true;
    }

    if (X == 4)
    {
        if (C != 4) return false;

        if (R == 1 || R == 2)
        {
            return false;
        }
        if (R == 3 || R == 4)
        {
            return true;
        }
    }

    if (X == 5)
    {
        return check5(R, C);
    }

    if (X == 6)
    {
        return check6(R, C);
    }

    return false;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        int X, R, C;
        cin >> X >> R >> C;
        bool secondWin = check(X, R, C);
        if (secondWin)
        {
            cout << "Case #" << csIx << ": GABRIEL" << endl;
        }
        else
        {
            cout << "Case #" << csIx << ": RICHARD" << endl;
        }
    }
    
    return 0;
}
