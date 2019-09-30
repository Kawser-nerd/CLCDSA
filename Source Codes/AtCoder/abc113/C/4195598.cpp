#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n, m, p, y;
    cin >> n >> m;
    vector<vector<pair<int, int>>> info(n+1);
    map<int, pair<int, int>> map_id;

    for (int i=0; i<m; ++i){
        cin >> p >> y;
        info[p].push_back(make_pair(y, i));
    }
    for (int i=1; i<=n; ++i){
        sort(info[i].begin(), info[i].end());
    }
    for (int i=1; i<=n; ++i){
        for (int j=0; j<(int)info[i].size(); ++j){
            map_id.insert(make_pair(info[i][j].second, make_pair(i, j+1)));
        }
    }
    for (int i=0; i<m; ++i){
        pair<int, int> ppair = map_id.at(i);
        printf("%06d", ppair.first);
        printf("%06d", ppair.second);
        cout << endl;
    }
    return 0;
}