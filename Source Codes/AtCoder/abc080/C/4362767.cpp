#include<iostream>
#include<string>
#include<vector>

using namespace std;
#define ll long long
int F[105][11];
int P[105][11];

int main(){
    int N,A,B;
    int ans = -1e9;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            cin >> F[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 11; j++){
            cin >> P[i][j];
        }
    }

    for(int bit = 1; bit < 1 << (10); bit++){
        // ?????bit?????????
        int sum = 0;
		for(int j = 0; j < N; j++){
            int cnt = 0;
            for(int k = 0; k < 10; k++){
			    if (bit & (1 << k) && F[j][k]) cnt++;
            }
            sum += P[j][cnt];
		}
        ans = max(ans, sum);
    }
    
    cout << ans << endl;
}