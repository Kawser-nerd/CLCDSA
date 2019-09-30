#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    int n, d;
    cin >> n;
    set<int> kagamimochi;
    for (int i=0; i<n; ++i){
        cin >> d;
        kagamimochi.insert(d);
    }
    cout << kagamimochi.size() << endl;
    return 0;
}