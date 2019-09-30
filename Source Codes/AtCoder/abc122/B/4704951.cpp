#include <iostream>
#include <string>
using namespace std;
int main(){
     string s;
    string a = "ACGT";
    cin >> s;
    int ans = 0;
    int tem = 0;
    bool flag = true;
    for(int i = 0;i<s.size();i++){
        for(int j = 0;j<4;j++){
            if(s[i] == a[j]){
                tem++;
                flag = false;
                break;
            }
        }
        if(flag){
            ans = max(ans,tem);
            tem = 0;
        }
        else{
            flag = true;
        }
    }
    ans = max(ans,tem);
    cout << ans << endl;
}