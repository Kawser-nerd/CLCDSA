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
using namespace std;

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        int S;
        cin >> S;
        string ss;
        cin >> ss;

        int currStanding = 0;
        int added = 0;

        for (int s = 0; s <= S; ++s)
        {
            int needToAdd = max(s - currStanding, 0);

            currStanding += ss[s] - '0';
            currStanding += needToAdd;
            added += needToAdd;
        }

        cout << "Case #" << csIx << ": " << added << endl;
    }
    
    return 0;
}
