#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int d[51][51];
int a[51], b[51];
int N, M;

bool dfs(){
    bool visited[N+1];
    REP(i,N+1)visited[i] = false;

    stack<int> st;
    st.push(1);

    while(st.size() > 0){
        int v = st.top();
        st.pop();

        visited[v] = true;
        REP(i,N+1){
            if(d[v][i] == 1 && visited[i] == false){
                st.push(i);
            }
        }
    }

    FOR(i,1,N+1){
        if(visited[i] == false){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> N >> M;

    REP(i,N+1)REP(j,N+1)d[i][j] = 0;

    REP(i,M){
        cin >> a[i] >> b[i];
        d[a[i]][b[i]] = 1;
        d[b[i]][a[i]] = 1;
    }

    int ans = 0;
    REP(i,M){
        d[a[i]][b[i]] = 0;
        d[b[i]][a[i]] = 0;
        if(dfs()){
        }else{
            ans++;
        }
        d[a[i]][b[i]] = 1;
        d[b[i]][a[i]] = 1;
    }

    cout << ans << endl;

    return 0;
}