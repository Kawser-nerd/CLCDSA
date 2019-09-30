#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]=='p'){
                ans--;
            }
        }else{
            if(s[i]=='g'){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}