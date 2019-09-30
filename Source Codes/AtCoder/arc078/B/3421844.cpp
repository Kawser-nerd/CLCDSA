#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

vector<vector <int>> graph;
vector<int> d_fennec, d_snuke;

// k -> start, p -> prev node, n -> goal node
// d -> distance, flag -> 0(fennec), 1(snuke)
void search_path(int k, int p, int n, int d, int flag)
{
    if(flag == 0){
        d_fennec[k] = d;
    }
    else if(flag == 1){
        d_snuke[k] = d;
    }
    
    for(auto itr=graph[k].begin(); itr != graph[k].end(); ++itr){
        if(*itr != p){
            search_path(*itr, k, n, d+1, flag);
        }
    }
    return;
}

int main()
{
    int n, a, b, get_fennec, get_snuke;
    get_fennec = 0;
    get_snuke = 0;
    vector<int> path_t;
    string answer;
    cin >> n;
    graph.resize(n+1);
    d_fennec.resize(n+1);
    d_snuke.resize(n+1);
    for(int i=0; i<n; ++i){
        if(i != n-1){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        d_fennec[i] = 100000;
        d_snuke[i] = 100000;
    }
    // search fennec -> snuke path
    search_path(1, 0, n, 0, 0);
    // search snuke -> fennec path
    search_path(n, 0, 1, 0, 1);
    // check distance
    for(int i=1; i<=n; ++i){
        if(d_fennec[i] <= d_snuke[i]){
            get_fennec++;
        }
        else {
            get_snuke++;
        }
        // cout << i << " @ df: " << d_fennec[i] << " * ds: " << d_snuke[i] << endl;
        // cout << "point (fennec, snuke) -> (" << get_fennec << ", " << get_snuke << ")" << endl;
    }
    if(get_fennec > get_snuke){
        answer = "Fennec";
    }
    else {
        answer = "Snuke";
    }
    cout << answer << endl;
}