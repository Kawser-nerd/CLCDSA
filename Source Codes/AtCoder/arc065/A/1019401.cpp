#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define loop(i,n) for(int i=0;i<n;i++)

int main(){
    
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    
    while(1){
        if (s==""){
            cout<<"YES"<<endl;
            return 0;
        }
        else if(s.substr(0,7)=="remaerd")
            s=s.substr(7);
        else if(s.substr(0,6)=="resare")
            s=s.substr(6);
        else if(s.substr(0,5)=="maerd"||s.substr(0,5)=="esare")
            s=s.substr(5);
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    return 0;
}