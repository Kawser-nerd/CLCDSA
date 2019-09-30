#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.length();i++){
        int j;
        for(j=0;j<s.length();j++){
            if(s[j]!=t[(i+j)%s.length()])break;
        }
        if(j==s.length()){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
}