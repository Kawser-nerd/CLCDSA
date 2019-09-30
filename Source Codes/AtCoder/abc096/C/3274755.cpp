#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    int H, W;
    vector <string> s;
    string sub;
    bool judge = true;
    
    cin >> H >> W;
    
    for(int i = 0; i < H; i++){
        cin >> sub;
        s.push_back(sub);
    }
    
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            
            if(s[i][j] == '#'){
                judge = false;
                
                for(int k = 0; k < 4; k++){
                    // cout << i << " " << j << " " << k << endl;
                    
                    if(i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < H && j + dy[k] < W){
                        if(s[i + dx[k]][j + dy[k]] == '#'){
                            judge = true;
                            // cout << k << endl;
                            break;
                        }
                    }
                }
            }
            
            if(!judge){
                break;
            }
        }
        
        if(!judge){
            break;
        }
    }
    
    if(judge){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}