#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N, M, ans = 0;
    int tmp = 0;
    string a;
    vector<string> s, t;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> a;
        s.push_back(a); 
    } 
    cin >> M;
    for(int i = 0 ; i < M; i++){
        cin >> a;
        t.push_back(a); 
    } 

    for(int i = 0 ; i < N; i++){
        tmp = 1;
        for(int j = 0 ; j < M; j++){
            if(s[i] == t[j]) tmp--;
        }
        for(int j = 0 ; j < N; j++){
            if(i != j && s[i] == s[j]) tmp++;
        }
        if(ans < tmp) ans = tmp;
    }
    cout << ans << endl;
}