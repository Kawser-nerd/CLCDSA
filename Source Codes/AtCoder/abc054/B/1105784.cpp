#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    string ans = "No";
    vector<string> A, B;

    for(int i = 0; i < N; i++){
        string tmp; cin >> tmp; A.push_back(tmp);
    }

    for(int i = 0; i < M; i++){
        string tmp; cin >> tmp; B.push_back(tmp);
    }



    for(int i = 0; i <= N-M; i++){
        for(int j = 0; j <= N-M; j++){
            bool flag = true;
            for(int k = 0; k < M; k++){
                for(int l = 0; l < M; l++){
                    if(A[i+k][j+l] != B[k][l]){
                        flag = false;
                        break;
                    }
                }
                if(flag == false) break;
            }
            if(flag == true){
                ans = "Yes";
                break;
            }
        }
        if(ans == "Yes"){
            break;
        }
    }

    cout << ans << endl;

    return 0;
}