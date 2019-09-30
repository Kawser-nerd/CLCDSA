#include <iostream>
using namespace std;
int n;
int a[300][300];
bool b[300][300];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n - 1; ++i){
        for(int j = i; j < n; ++j){
            b[i][j] = true;
        }
    }


    for(int i = 0; i < n-2; ++i){
    for(int j = i+1; j < n-1; ++j){
    for(int k = j+1; k < n; ++k){
        if(a[i][j] + a[j][k] < a[i][k] || a[i][k] + a[k][j] < a[i][j] || a[k][i] + a[i][j] < a[j][k]){
            cout << -1 << endl;
            return 0;
        }
        else if(a[i][j] + a[j][k] == a[k][i]){
            b[i][k] = false;
        }else if(a[i][k] + a[k][j] == a[i][j]){
            b[i][j] = false;
        }else if(a[k][i] + a[i][j] == a[j][k]){
            b[j][k] = false;
        }else {}
    }
    }
    }
    long long ans = 0;
    for(int i = 0; i < n - 1; ++i){
        for(int j = i; j < n; ++j){
            if(b[i][j])ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}