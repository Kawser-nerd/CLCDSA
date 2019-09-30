#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
typedef long long ll;

int T, N, C;

int main()
{
    ifstream in("C.in");
    ofstream out("C.out");
    
    in >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        in >> N;
        int minC = 1000000, total = 0, fakeTotal = 0;
        for (int i = 0; i < N; ++i)
        {
            in >> C;
            minC = min(C, minC);
            total += C;
            fakeTotal ^= C;
        }
        if (fakeTotal != 0)
            out << "Case #" << tc << ": NO" << endl;
        else
            out << "Case #" << tc << ": " << (total-minC) << endl;
    }
}
