#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
using namespace std;

int main(){

    int time1, time2;
    int N;
    int mintime = 200;
    int mintime1 = 200;
    cin >> N;
    int t[N];
    for(int i = 0; i < N; ++i) cin >> t[i];

    for(int bit = 0; bit < (1 << N); ++bit){
        time1 = 0;
        time2 = 0;
        for(int i = 0; i < N; ++i){
            if( (bit & (1 << i) ) ){
                time1 += t[i];
            }else{
                time2 += t[i];
            }
        }
        if(time1 == 0){
            mintime1 = time2;
        }else if(time2 == 0){
            mintime1 = time1;
        }else{
            mintime1 = max(time1,time2);
        }
        mintime = min(mintime, mintime1);
    }
    cout << mintime << endl;
}