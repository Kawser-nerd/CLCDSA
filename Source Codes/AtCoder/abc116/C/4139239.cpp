#include <iostream>
#include <vector>

using namespace std;

//=================================================================
// Begginer Contest 116 C
int main(){
    int N;
    cin >> N;
    vector<int> h(N);
    int ans = 0;

    for(int i=0 ; i<N ; i++){
        cin >> h[i];
    }

    while(true){
        bool cont = false;
        int sum=0;
        for(int i=0 ; i<N ; i++){
            sum += h[i];
            if(h[i]>0 && cont==false){
                h[i]--;
                cont = true;
            }
            else if(h[i]>0 && cont==true){
                h[i]--;
                continue;
            }else if(cont==true){
                ans++;
                cont = false;
            }
        }
        if(cont==true){
            ans++;
        }
        if(sum==0){
            break;
        }
    }
    cout << ans << endl;
}