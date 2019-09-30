#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, cnt = 0, maxv = 0;
    string s;
    cin >>n >>s;
    for(int i =0; i < s.length(); i++){
        if(s[i] == 'I'){
            cnt++;
        }else if(s[i] == 'D'){
            cnt--;
        }
        maxv = max(maxv,cnt);
    }
    cout << maxv << endl;
}