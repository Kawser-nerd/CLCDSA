#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>

using namespace std;

int N;
int v[10];
int edge[10][10];
int ans;

int dfs(int crt){
    v[crt] = 1;
    int flag = 1;
    for (int i = 1; i <= N; i++){
        if (!v[i]) flag = 0;
    }
    if (flag) ans++;
    
    for (int i = 1; i <= N; i++){
        if (edge[crt][i] == 1 && v[i] != 1){
            dfs(i);
        }
    }
    v[crt] = 0;
    return 0;
}

int main(){
    cin.tie(0);
    
    int M; cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    
    dfs(1);
    cout << ans << endl;
}