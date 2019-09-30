#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, sec;
    cin >> n;
    vector<int> c(n);
    vector<int> s(n);
    vector<int> f(n);
    vector<int> answer(n+1, 0);
    for(int i=1; i<=n-1; ++i){
        cin >> c[i] >> s[i] >> f[i];
    }
    for(int i=1; i<=n; ++i){
        if(i == n){
            cout << answer[i] << endl;
            break;
        }
        else {
            sec = 0;
            for(int j=i; j<n; ++j){
                if(sec >= s[j]){
                    sec += c[j] + ((sec % f[j] == 0) ? 0 : (f[j] - (sec % f[j])));
                }
                else {
                    sec = s[j] + c[j];
                }
            }
        }
        cout << sec << endl;
    }
}