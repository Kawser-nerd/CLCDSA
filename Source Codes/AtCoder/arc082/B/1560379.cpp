#include <iostream>
using namespace std;

int n;
int a[100009];
int main(){
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n;++i){
        scanf("%d", &a[i]);
    }
    for(int i = 1 ; i <= n;++i){
        if(i == a[i]){
            ans++;
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}