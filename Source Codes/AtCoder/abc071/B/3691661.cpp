#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    char s[101000];
    cin >> s;
    bool a[26]={false};
    for(int i=0;s[i]!='\0';i++)a[s[i]-'a']=true;
    for(int i=0;i<26;i++){
        if(!a[i]){
            cout << (char)(i+'a') <<endl;
            return 0;
        }
    }
    cout << "None" << endl;
}