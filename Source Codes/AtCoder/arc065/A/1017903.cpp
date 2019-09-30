#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int main(){
    string S;
    cin>>S;
    for(int i=0;i<S.size();i++){
        if(S.substr(i,10)=="dreamerase"){//dream+rease
            i+=4;
        }else if(S.substr(i,7)=="dreamer"){
            i+=6;
        }else if(S.substr(i,5)=="dream"){
            i+=4;
        }else if(S.substr(i,6)=="eraser"){
            i+=5;
        }else if(S.substr(i,5)=="erase"){
            i+=4;
        }else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}