#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it;}cout<<endl;}

int main() {
    ll a,b;
    bool flag = true;
    cin>>a>>b;
    pr("100 100");
    if (b<a) {
        swap(a, b);
        flag=false;
    }// a <= b
    
    ll sa=1,sb=0;
    char m[100][100];
    rep(i, 100) rep(j,100) m[i][j]='.';
    
    bool kisu = false;
    ll  endline=0;
    rep(i, 100) {
        kisu = !kisu;
        if (kisu) {
            rep(j,50){
                if (a==sa || b==sb) {
                    endline=i;
                    break;
                }
                m[i][2*j+1]='#';
                if (i!=0) {
                    sa++;
                    sb++;
                }else{
                    sb++;
                }
            }
        }else{
            rep(j,50){
                if (a==sa || b==sb) {
                    endline=i;
                    break;
                }
                m[i][2*j]='#';
                sa++;
                sb++;
            }
        }
        if (a==sa || b==sb) {
            endline=i;
            break;
        }
    }
    
    if (a==sa) {
        fr(i,endline+2,100){
            if(b==sb) break;
            rep(j,50){
                if(b==sb) break;
                m[i][2*j]='#';
                sb++;
            }
            i++;
        }
    }else{ // b==sb
        rep(j,100){
            if(a==sa) break;
            if(j!=0 && j!=99 && m[endline][j]=='#'){
                if(a==sa) break;
                fr(i, endline, 100){
                    m[i][j]='#';
                }
                sa++;
                if(a==sa) break;
            }
            if(j!=0 && j!=99 && m[endline-1][j]=='#' && m[endline][j+1]!='#'&& m[endline][j-1]!='#'){
                if(a==sa) break;
                fr(i, endline-1, 100){
                    m[i][j]='#';
                }
                sa++;
                if(a==sa) break;
            }
            if(a==sa) break;
        }
    }
    
    if(!(a==sa&&b==sb)) {m[98][0] = '#';m[98][1] = '#';sa++;}
    if(!(a==sa&&b==sb)) {m[98][99] = '#';m[98][98] = '#';sa++;}
    rep(i, 100) {
        rep(j,100) {
            if (flag) {
                cout<<m[i][j];
            }else{
                cout<<(m[i][j] == '#' ? '.':'#');
            }
        }
        cout<<endl;
    }
//        cout<<(a==sa&&b==sb)<<endl;
}