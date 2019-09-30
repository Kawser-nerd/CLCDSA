#include <iostream>
using namespace std;

typedef long long ll;

int T, N;
int m[1005];

int main(){
    cin >> T;

    for(int t=1; t<=T; t++){
        cin >> N;
        
        ll A1 = 0, A2 = 0;
        int R = 0;
        
        for(int i=0; i<N; i++) {
            cin >> m[i];
            if(i>0 && m[i] < m[i-1]) {
                A1 += m[i-1] - m[i];
                R = max(R, m[i-1] - m[i]);
            }
        }


        for(int i=1; i<N; i++){
            if(m[i-1] >= R) A2 += R;
            else A2 += m[i-1];
        }

        cout << "Case #" << t << ": " << A1 << " " << A2 << "\n";
    }
}
