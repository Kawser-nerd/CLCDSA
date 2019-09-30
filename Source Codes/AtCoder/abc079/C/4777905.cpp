#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

bool bit(int mask, int position){
    if((1 & (mask >> position)) != 0) return true;
    return false;
}

int main(){
    string s; cin >> s;
    
    int size = s.length() - 1;
    vector<char> sign(3);

    for(int i = 0; i < (1<<size); i++){
        sign.clear();
        int tmp = (s[0]- '0');
        for(int j = 0; j < size; j++){
            if(bit(i, j)){
                tmp += (s[j+1]- '0');
                sign.push_back('+');
            } else{
                tmp -= (s[j+1]-'0');
                sign.push_back('-');
            }
        }
        if(tmp == 7) break;
    }
    
    
    cout << s[0] << sign[0] << s[1] << sign[1] << s[2] << sign[2] << s[3] << "=7" <<endl;


    return 0;
}