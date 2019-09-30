#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::stack;

vector<bool> dfs(int n, const vector<vector<bool>>& c, int v_init){
    stack<int> stack;
    vector<bool> visited(n, false);
    stack.push(v_init);
    while(!stack.empty()){
        int v = stack.top();
        stack.pop();

        if(visited[v]){
            continue;
        }

        visited[v] = true;
        for(int i = 0; i < n; i++){
            if(c[v][i] && !visited[i]){
                stack.push(i);
            }
        }
    }
    return visited;
}


int main(void){
    int n, m;
    cin >> n >> m;

    vector<int> ea(m);
    vector<int> eb(m);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ea[i] = a - 1;
        eb[i] = b - 1;
    }


    vector<vector<bool>> c(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        c[ea[i]][eb[i]] = true;
        c[eb[i]][ea[i]] = true;
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        c[ea[i]][eb[i]] = false;
        c[eb[i]][ea[i]] = false;

        vector<bool> visited = dfs(n, c, 0);
        cnt += std::count(visited.begin(), visited.end(), true) != n;

        c[ea[i]][eb[i]] = true;
        c[eb[i]][ea[i]] = true;
    }
    cout << cnt << endl;

    return 0;
}