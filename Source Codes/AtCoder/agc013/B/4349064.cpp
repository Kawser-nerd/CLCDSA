#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int N, M;
    vector<int> G[100000];
    bool used[100000];
    int ans[100000];
    int ans_idx = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) used[i] = false;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    stack<int> st;
    st.push(0);
    used[0] = true;
    while(true){
        int top = st.top();
        for(int i = 0; i < G[top].size(); i++){
            if(!used[G[top][i]]){
                st.push(G[top][i]);
                used[G[top][i]] = true;
                break;
            }
        }
        if(top == st.top()) break;
    }
    while(!st.empty()){
        ans[ans_idx] = st.top();
        ans_idx++;
        st.pop();
    }
    int tmp = 0;
    
    while(true){
        bool flag = true;
        for(int i = 0; i < G[tmp].size(); i++){
            if(!used[G[tmp][i]]){
                tmp = G[tmp][i];
                ans[ans_idx] = tmp;
                ans_idx++;
                used[tmp] = true;
                flag = false;
                break;
            }
        }
        if(flag) break;
    }
    cout << ans_idx << endl;
    for(int i = 0; i < ans_idx; i++){
        cout << ans[i]+1;
        if(i == ans_idx-1) cout << endl;
        else cout << ' ';
    }
}