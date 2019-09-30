#include<iostream>
#include<string>

using namespace std;

int main(){
    double x,ans = 0.0;
    string s;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> s;
        if(s == "JPY") ans+=x;
        else ans += x*380000.0;
    }
    cout << ans << endl;
}