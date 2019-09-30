#include <iostream>
#include <string>

using namespace std;

int S_a[100001];
int S_b[100001];
int T_a[100001];
int T_b[100001];

int main(){
    string S, T;
    cin >> S;
    cin >> T;
    int q;
    cin >> q;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'A'){
            S_a[i+1] = S_a[i]+1;
            S_b[i+1] = S_b[i];
        }
        if(S[i] == 'B'){
            S_a[i+1] = S_a[i];
            S_b[i+1] = S_b[i]+1;
        }
    }
    for(int i = 0; i < T.size(); i++){
        if(T[i] == 'A'){
            T_a[i+1] = T_a[i]+1;
            T_b[i+1] = T_b[i];
        }
        if(T[i] == 'B'){
            T_a[i+1] = T_a[i];
            T_b[i+1] = T_b[i]+1;
        }
    }
    for(int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int diff_S = (S_a[b] - S_a[a-1]) - (S_b[b] - S_b[a-1]);
        //cout << (S_a[b] - S_a[a-1]) << ' ' << (S_b[b] - S_b[a-1]) << endl;
        diff_S = (diff_S%3 + 3)%3;
        int diff_T = (T_a[d] - T_a[c-1]) - (T_b[d] - T_b[c-1]);
        diff_T = (diff_T%3 + 3)%3;
        //cout << (T_a[d] - T_a[c-1]) << ' ' << (T_b[d] - T_b[c-1]) << endl;
        if(diff_S == diff_T) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}