#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void){
    int N;
    cin >> N;

    int F[100][15];
    int P[100][15];
    int ans;
    ans = -(1<<30);

    for(int i=0;i<N;i++){
        for(int j=0;j<10;j++){
            cin >> F[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<11;j++){
            cin >> P[i][j];
        }
    }

    for(int i=1;i<(1<<10);i++){
        int sum=0;
        for(int j=0;j<N;j++){
            int c = 0;
            for(int k=0;k<10;k++){
                if((i>>k)&1 && F[j][k]){
                    c++;
                }
            }
            sum = sum + P[j][c];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;

}