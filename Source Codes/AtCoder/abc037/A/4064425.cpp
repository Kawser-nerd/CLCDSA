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
    int A, B, C;
    cin >> A >> B >> C;
    int ans = C / min(A, B);
    ans += (C - (ans * min(A, B))) / max(A, B);
    cout << ans << endl;
    return 0;
}