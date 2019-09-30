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
    int n, m;
    cin >> n;
    set<string> str;
    string s;
    map<string, int> mapping;
    for (int i=0; i<n; ++i){
        cin >> s;
        str.insert(s);
        if(mapping.find(s) == mapping.end()){
            mapping.insert(make_pair(s, 1));
        }
        else {
            int yen = mapping.at(s);
            mapping.erase(s);
            mapping.insert(make_pair(s, yen+1));
        }
    }
    cin >> m;
    for (int i=0; i<m; ++i){
        cin >> s;
        str.insert(s);
        if(mapping.find(s) != mapping.end()){
            int yen = mapping.at(s);
            mapping.erase(s);
            if(yen - 1 > 0){
                mapping.insert(make_pair(s, yen-1));
            }
        }
    }
    int ans = 0;
    for (auto itr = str.begin(); itr != str.end(); ++itr){
        if(mapping.find(*itr) != mapping.end()){
            ans = max(ans, mapping.at(*itr));
        }
    }
    cout << ans << endl;
    return 0;
}