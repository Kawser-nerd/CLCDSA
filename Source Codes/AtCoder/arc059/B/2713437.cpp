#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin>>S;
    for(int i=0;i<S.size()-1;i++){
        if(S[i]==S[i+1]){
            cout<<i+1<<' '<<i+2<<endl;
            return 0;
        }
    }
    for(int i=0;i<S.size()-2;i++){
        if(S[i]==S[i+2]){
            cout<<i+1<<' '<<i+3<<endl;
            return 0;            
        }
    }

    cout<<-1<<' '<<-1<<endl;
    return 0;
}