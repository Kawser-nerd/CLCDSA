#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    int N;
    vector <string> s;
    string str;
    bool judge = true;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        s.push_back(str);
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(s[j] == s[i]){
                judge = false;
            }
        }
        
        for(int j = i + 1; j < N; j++){
            if(s[j] == s[i]){
                judge = false;
            }
        }
        
        if(!judge){
            break;
        }
    }
    
    for(int i = 1; i < N; i++){
        if(s[i - 1][s[i - 1].length() - 1] != s[i][0]){
            judge = false;
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