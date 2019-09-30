# include <iostream>
#include <string.h>

using namespace std;

int main(){
    string S;
    cin>>S;
    int a[5];
    for(int i=0;i<4;i++)cin>>a[i];
    int j=0;
    for(int i=0;i<S.size();i++){
        if(a[j]==i){
            cout<<'"';
            j++;
        }
        cout<<S[i];
    }
    if(j<4)cout<<'"';
    cout<<endl;
    return 0;
}