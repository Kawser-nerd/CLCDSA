#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef vector<int> Node;
typedef vector<Node> Graph;


int main(){
    int T;
    cin >> T;
    for(int casenum = 1; casenum <= T; casenum++){
        printf("Case #%d: ", casenum);
        int N, M;
        cin >> N >> M;
        vector<string> code(N);
        REP(i, N) cin >> code[i];

        int d[55][55] = {};
        Graph G(N);
        REP(i, M){
            int a, b;
            cin >> a >> b;
            a--; b--;
            d[a][b] = d[b][a] = true;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int start = -1;
        REP(s, N){
            bool used[55] = {};
            int cnt = 0;
            function<void(int)> dfs = [&](int u) {
                assert(!used[u]);
                used[u] = true;
                cnt ++;
                for(int v : G[u]){
                    if(!used[v]){
                        dfs(v);
                    }
                }
            };
            dfs(s);
            if(cnt == N && (start == -1 || code[start] > code[s])){
                start = s;
            }
        }

        assert(start != -1);

        vector<int> ans;
        stack<int> stk;
        bool arrived[55] = {};

        ans.push_back(start);
        stk.push(start);
        arrived[start] = true;
        // cout << "add " << start + 1 << endl;

        set<int> cand;
        for(int v : G[start]){
            cand.insert(v);
        }

        while(ans.size() < N){
            int next = -1;

            for(int u : cand) if(!arrived[u]) {
                stack<int> local_stk = stk;
                while(local_stk.size() > 0){
                    int s = local_stk.top();
                    if(d[s][u]) break;
                    local_stk.pop();
                }

                bool used[55] = {};
                memcpy(used, arrived, sizeof(used));

                function<void(int)> dfs = [&](int cur) {
                    used[cur] = true;
                    for(int v : G[cur]){
                        if(!used[v]){
                            dfs(v);
                        }
                    }
                };

                while(local_stk.size() > 0){
                    int s = local_stk.top();
                    dfs(s);
                    local_stk.pop();
                }

                int cnt = 0;
                REP(i, N) if(used[i]) cnt++;

                if(cnt == N && (next == -1 || code[next] > code[u])){
                    next = u;
                }
            }

            assert(next != -1);

            while(stk.size() > 0){
                int s = stk.top();
                if(d[s][next]) break;
                stk.pop();
            }

            ans.push_back(next);
            stk.push(next);
            arrived[next] = true;
            for(int v : G[next]){
                cand.insert(v);
            }
            // cout << "add " << next + 1 << endl;
        }
        for(auto ai : ans){
            cout << code[ai];
        }
        cout << endl;
    }
    return 0;
}

