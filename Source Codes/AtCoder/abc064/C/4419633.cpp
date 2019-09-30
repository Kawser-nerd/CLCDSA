#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define LL long long 

int main(){
    int n;
    bool hf = false, cf = false, mf = false, sf = false, af = false;
    bool kf = false, of = false, akaf = false; 
    LL ans = 0;
    int mincnt = 0;
    int maxcnt = 0;
    cin >> n;
    vector<LL> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] < 400){
            if(!hf) mincnt++;
            hf = true;
        }else if(a[i] < 800){
            if(!cf) mincnt++;
            cf = true;
        }else if(a[i] < 1200){
            if(!mf) mincnt++;
            mf = true;
        }else if(a[i] < 1600){
            if(!sf) mincnt++;
            sf = true;
        }else if(a[i] < 2000){
            if(!af) mincnt++;
            af = true;
        }else if(a[i] < 2400){
            if(!kf) mincnt++;
            kf = true;
        }else if(a[i] < 2800){
            if(!of) mincnt++;
            of = true;
        }else if(a[i] < 3200){
            if(!akaf) mincnt++;
            akaf = true;
        }else{
            maxcnt++;
        }
    }
    cout << max(mincnt, 1) << " " << maxcnt + mincnt << endl;

}