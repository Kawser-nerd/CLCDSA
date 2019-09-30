#include <iostream>
#include <string>

using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.size();
    if(S[0] != S[N-1]){
        if(N%2 == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    }else{
        if(N%2 == 0) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}