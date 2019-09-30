#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sum_s[100005], sum_t[100005];
int sa(int a,int b){
    return sum_s[b] - sum_s[a-1];
}
int sb(int a,int b){
    return b-a+1-sa(a,b);
}
int ta(int a,int b){
    return sum_t[b] - sum_t[a-1];
}
int tb(int a,int b){
    return b-a+1 - ta(a,b);
}


int main(){
    string s,t;
    cin >> s >> t;
    int q; cin >> q;
    sum_s[0] = 0;
    sum_t[0] = 0;
    for(int i=1;i<s.length()+1;i++)  sum_s[i] = sum_s[i-1] + (s[i-1]=='A' ? 1 : 0);
    for(int i=1;i<t.length()+1;i++)  sum_t[i] = sum_t[i-1] + (t[i-1]=='A' ? 1 : 0);
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int aa = sa(a,b) + 2*sb(a,b), bb = ta(c,d) + 2*tb(c,d);
        //cout << " "<< bb << endl;
        if(aa < bb) swap(aa,bb);
        if((aa - bb) % 3 ==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}