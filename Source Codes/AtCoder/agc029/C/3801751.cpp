#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
using namespace std;

typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n){
        cin >> a[i];
    }
    int ok = 200000;
    int ng = 1;
    bool flag = 1;
    rep(i,n-1){
        if(a[i]>=a[i+1]){
            flag = 0;
            break;
        }
    }
    if(flag){
        cout << 1 << endl;
        return 0;
    }
    //ok = 3;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        //cerr << ok << " " << ng << endl;
        
        int tmp = 1;
        int p = 0;
        rep(i,100){
            tmp*=mid;
            if(tmp>=200001){
                p = i+1;
                break;
            }
        }
        p++;
        tmp *= mid;
        //cerr << mid << " " << p << " " << tmp << endl;
        vector<int> s(8);
        //int s = 0;
        int ss = 0;
        int sst = 0;
        int ssss = 0;
        bool sss = 1;
        rep(i,n-1){
            //cerr << i << " " << s << endl;
            if(a[i]<a[i+1]){
                continue;
            }
            if(a[i+1]>=8*p){
                continue;
            }
            int x = (a[i+1]-1)/p;
            for(int j=x+1;j<8;j++){
                s[j] = 0;
            }
            int k = a[i+1];
                k-=x*p;
                int t = 1;
                for(int j=k;j<p;j++){
                    t *= mid;
                }
                s[x]/=t;
                s[x] = (s[x]+1)*t;
                if(s[x]>=tmp){
                    if(x==0){
                        sss = 0;
                        break;
                    }
                    s[x-1]+=1;
                    s[x] = 0;
                }
            // if(a[i+1]<=p){
            //     ss = 0;
            //     sst = 0;
            //     ssss = 0;
            //     int k = a[i+1];
            //     int t = 1;
            //     for(int j=k;j<p;j++){
            //         t *= mid;
            //     }
            //     s/=t;
            //     s = (s+1)*t;
                
            //     if(s>=tmp){
            //         sss = 0;
            //         break;
            //     }
            // }else if(a[i+1]<=2*p){
            //     sst = 0;
            //     ssss = 0;
            //     int k = a[i+1];
            //     k-=p;
            //     int t = 1;
            //     for(int j=k;j<p;j++){
            //         t *= mid;
            //     }
            //     ss/=t;
            //     ss = (ss+1)*t;
            //     if(ss>=tmp){
            //         s+=1;
            //         ss = 0;
            //     }
            // }else if(a[i+1]<=3*p){
            //     ssss = 0;
            //     int k = a[i+1];
            //     k-=2*p;
            //     int t = 1;
            //     for(int j=k;j<p;j++){
            //         t *= mid;
            //     }
            //     sst/=t;
            //     sst = (sst+1)*t;
            //     if(sst>=tmp){
            //         ss+=1;
            //         sst = 0;
            //     }
            // }else if(a[i+1]<=4*p){
            //     int k = a[i+1];
            //     k-=3*p;
            //     int t = 1;
            //     for(int j=k;j<p;j++){
            //         t *= mid;
            //     }
            //     ssss/=t;
            //     ssss = (ssss+1)*t;
            //     if(ssss>=tmp){
            //         sss+=1;
            //         ssss = 0;
            //     }
            // }
            if(s[0]>=tmp){
                sss = 0;
                break;
            }
        }
        if(sss){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    //cerr << ok << " " << ng << endl;
    cout << ok << endl;
    return 0;
}