#include<iostream>
#include<map>
using namespace std;


int main(){
    long H,W,N;
    cin >> H >> W >> N;

    long ans[10];
    for(int i=0; i<10; i++) ans[i] = 0;
    ans[0] = (H-2)*(W-2);
    map<string,int> m;

    for(int t=0; t<N; t++){
        long a, b;
        cin >> a >> b;
        for(int i = -1; i < 2; i++){
            for(int j=-1; j<2; j++){
                if (a+i < 2 || b+j < 2 || a+i > H-1 || b+j > W-1) continue;
                string s = to_string(a+i) + "-" + to_string(b+j);
                m[s] = m[s] + 1;
                ans[m[s]] += 1;
                ans[m[s]-1] -= 1;
            }
        }
    }


    for(int i=0; i<10; i++){
        cout << ans[i] << endl;
    }
}