#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    vector<string> s, t;

    cin >> N;
    s.resize(N, "");
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    cin >> M;
    t.resize(M, "");
    for(int i = 0; i < M; i++){
        cin >> t[i];
    }
    sort(t.begin(), t.end());

    vector<int> score;
    int i = 0;
    int j = 0;
    while(j < N){
        score.push_back(0);
        score[i] += count(s.begin(), s.end(), s[j]);
        int num = score[i];
        score[i] -= count(t.begin(), t.end(), s[j]);
        if(score[i] < 0){
            score[i] = 0;
        }
        j += num;
        i++;
    }
    sort(score.begin(), score.end());

    cout << score[score.size() - 1] << "\n";

    return 0;
}