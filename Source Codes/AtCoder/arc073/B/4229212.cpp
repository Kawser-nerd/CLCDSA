#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, W;
    cin >> N >> W;
    int v1[100000];
    int v2[100000];
    int v3[100000];
    int v4[100000];
    long sum1[100001];
    long sum2[100001];
    long sum3[100001];
    long sum4[100001];
    int n1 = 1, n2 = 0, n3 = 0, n4 = 0;
    int w1, v;
    cin >> w1 >> v;
    v1[0] = v;
    for(int i = 1; i < N; i++){
        int w;
        cin >> w >> v;
        if(w-w1 == 0){
            v1[n1] = v;
            n1++;
        }
        if(w-w1 == 1){
            v2[n2] = v;
            n2++;
        }
        if(w-w1 == 2){
            v3[n3] = v;
            n3++;
        }
        if(w-w1 == 3){
            v4[n4] = v;
            n4++;
        }
    }
    sort(v1, v1+n1, greater<int>());
    sort(v2, v2+n2, greater<int>());
    sort(v3, v3+n3, greater<int>());
    sort(v4, v4+n4, greater<int>());
    sum1[0] = 0;
    sum2[0] = 0;
    sum3[0] = 0;
    sum4[0] = 0;
    for(int i = 1; i <= n1; i++) sum1[i] = sum1[i-1]+v1[i-1];
    for(int i = 1; i <= n2; i++) sum2[i] = sum2[i-1]+v2[i-1];
    for(int i = 1; i <= n3; i++) sum3[i] = sum3[i-1]+v3[i-1];
    for(int i = 1; i <= n4; i++) sum4[i] = sum4[i-1]+v4[i-1];
    
    long ans = 0;
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            for(int k = 0; k <= n3; k++){
                for(int l = 0; l <= n4; l++){
                    if( w1*i+(w1+1)*j+(w1+2)*k+(w1+3)*l <= W){
                        ans = max(ans, sum1[i]+sum2[j]+sum3[k]+sum4[l]);
                        //cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << ans << endl;
                    }
                }
            }
        }
    }
    //cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << endl;
    cout << ans << endl;
}