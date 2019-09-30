#include <iostream>
#include <vector>

using namespace std;
using P = pair<int, int>;

int N, M;
bool adj[700][700];
int state[700];
bool dp[702];
bool dptmp[702];


template <typename T,typename U>                                                   
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

P dfs(int i, int taka = 1) {
    // cout << "    now on "<< i + 1 <<" col:"  << taka << endl; 
    state[i] = taka;
    bool fl = true;
    P ans = make_pair(0, 0);
    for (int k = 0; k < N; ++k) {
        if (!adj[i][k]) {
            //cout << k + 1 << endl;
            if (state[k] != 0) {
                if (state[k] != taka * -1) {
                    return make_pair(-1, -1);
                }
                continue;
            }
            fl = false;
            P recv = dfs(k, taka * -1);
            if (recv.first == -1) return make_pair(-1, -1);
            ans = ans + recv;
        }
    }
    P cur = taka == 1 ? make_pair(1, 0) : make_pair(0, 1);
    if (fl) {
        return cur;
    }
    return ans + cur;
}

int genans(int p) {
    int t = p;
    int h = N - p;
    return t * (t - 1) / 2 + h * (h - 1) / 2;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            adj[i][j] = false;
        }
        adj[i][i] = true;
    }
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        adj[A][B] = true;
        adj[B][A] = true;
    }
    for (int i = 0; i < N; ++i) state[i] = 0;

    // for (vector<int> adji : adj) {
    //     if (adji.size() == 0) continue;
    //     for (int tmp : adji) {
    //         cout << tmp << " ";
    //     }
    //     cout << endl;
    // }

    if (M == N * (N - 1) / 2) {
        cout << genans(N / 2) << endl;
        return 0;
    }

    vector<int> v;
    int sm = 0;
    for (int i = 0; i < N; ++i) {
        if (state[i] == 0) {
            //cout << "recv from " << i + 1 << endl;
            P tmp = dfs(i, 1);
            //cout << tmp.first << ", " << tmp.second << endl;
            if (tmp.first == -1) {
                cout << -1 << endl;
                return 0;
            }
            sm += tmp.first;
            v.push_back(tmp.second - tmp.first);
        }
    }
    //for (int vi : v) {
    //    cout << vi << endl;
    //}
    for (int i = 0; i < 702; i++) {
        dp[i] = false;
    }
    dp[sm] = true;
    for (int vk : v) {
        for (int i = 0; i < 702; ++i) {
            dptmp[i] = false;
            int prev = i - vk;
            if (prev >= 0 && prev < 702 && dp[prev])
                dptmp[i] = true;
        }
        for (int i = 0; i < 702; ++i) {
            dp[i] |= dptmp[i];
        }
    }

    for (int i = N / 2; i < N; i++) {
        if (dp[i] || dp[N - i]) {
            cout << genans(i) << endl;
            return 0;
        }
    }
}