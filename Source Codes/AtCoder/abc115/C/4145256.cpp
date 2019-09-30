#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//=================================================================
// Begginer Contest 115 C
int main(){
    int N,K;
    cin >> N >> K;
    vector<int> h(N,0);
    for(int i=0;i<N;i++){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    int min=10000000000;
    int tmp=0;
    for(int i=0;i<N-K+1;i++){
        tmp = h[i+K-1]-h[i];
        if(tmp<min){
            min = tmp;
        }
    }
    cout << min << endl;
} ./Main.cpp:17:13: warning: implicit conversion from 'long' to 'int' changes value from 10000000000 to 1410065408 [-Wconstant-conversion]
    int min=10000000000;
        ~~~ ^~~~~~~~~~~
1 warning generated.