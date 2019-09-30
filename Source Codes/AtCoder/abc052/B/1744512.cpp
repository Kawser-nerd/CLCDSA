#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    vector<int> a;
    int num =0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'I'){
            num++;
            a.push_back(num);
        }
        else if(s[i] == 'D'){
            num--;
            a.push_back(num);
        }
    }
    sort(a.begin(),a.end(),greater<int>());

    if(a[0] <= 0){cout << 0 << endl;}
    else cout << a[0] << endl;

  return 0;
}