#include <iostream>
using namespace std;
int main(void){
    string s;
    cin >>s;
    if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[0]){
        cout <<"SAME"<<endl;
    }else{
        cout <<"DIFFERENT"<<endl;
    }
    
   return 0; 
}