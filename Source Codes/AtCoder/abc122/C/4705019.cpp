#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    int l[q],r[q];
    for(int i = 0;i<q;i++){
        cin >> l[i] >> r[i];
    }
    int rs[s.size()];
    rs[0] = 0;
    for(int i = 1;i<s.size();i++){
        if(s[i] == 'C' && s[i-1] == 'A'){
            rs[i] = rs[i-1] + 1;
        }
        else{
            rs[i] = rs[i-1];
        }
    }
    for(int i = 0;i<q;i++){
        cout << rs[r[i]-1] - rs[l[i] - 1] << endl;
    }
}