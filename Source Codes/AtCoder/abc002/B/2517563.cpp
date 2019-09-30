#include <iostream>
using namespace std;
int main(void){
    int i;
    string s;
    
    cin >>s;
    
    for(i=0; i<s.size(); i++){
        if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'){
            
        }else{
            cout <<s[i];
        }
    }
    cout <<endl;
    return 0;
}