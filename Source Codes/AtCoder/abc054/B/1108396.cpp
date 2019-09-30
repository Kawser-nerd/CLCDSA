// ???1???wrong answer????????

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    int M;

    cin >> N >> M;

    vector<string> ar;
    vector<string> br;

    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        ar.push_back(s);
    }
    for(int i = 0; i < M; i++){
        cin >> s;
        br.push_back(s);
    }

    bool found = true;
    for(int i_a = 0; i_a < N; i_a++){
        found = true;
        for(int i_b = 0; i_b < M; i_b++){
            int tmp_i_a = i_a;
            size_t bt;
            size_t last_bt = 100;
            bt = ar[tmp_i_a].find(br[i_b]);
            if(bt == string::npos){
                found = false;
                break;
            }else{
                if(last_bt != 100){
                    if(bt != last_bt){
                        found = false;
                        break;
                    }
                }
                ++tmp_i_a;
                continue;
            }
        }
    }

    found ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}