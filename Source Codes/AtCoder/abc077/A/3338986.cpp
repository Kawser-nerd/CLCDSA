#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string c1, c2;
    int res=0;

    cin >> c1;
    cin >> c2;
    for(int i=0; i<3; ++i){
        if(c1[i] == c2[2-i]){
            res ++;
        }
    }
    if(res == 3) cout << "YES" << endl;
    else cout << "NO" << endl;
}

//int main(){
//    int res;
//    string s[6];
//    for(int i=0; i<3; ++i){
//        cin >> s[i];
//    }
//    for(int i=3; i<6; ++i){
//        cin >> s[i];
//    }
//    cout << s << endl;
//    for(int i=0; i<3; ++i){
//        if(s[i] == s[2-i]){
//            res ++;
//        }
//    }
//    if(res==3) cout<<"YES"<< endl;
//    else cout << "NO" << endl;
//}