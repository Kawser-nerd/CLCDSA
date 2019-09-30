#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int a,L,N,C,A[1005];
long long T;
struct cmp {
       bool operator () (int a,int b) {return a>b;}
};
multiset<int,cmp> P;
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    cin>>a;
    for (int t=1;t<=a;++t) {
        cout<<"Case #"<<t<<": ";
        cin>>L>>T>>N>>C;
        for (int i=0;i<C;++i) scanf("%d",&A[i]);
        P.clear();
        long long sum=0;
        bool flag=false;
        for (int i=0;i<N;++i) {
            if (flag) P.insert(A[i%C]);
            else if (sum<=T && sum+2*A[i%C]>T) {P.insert((sum+2*A[i%C]-T)/2);flag=true;}
            sum+=2*A[i%C];
        }
        int cnt=1;
        for (multiset<int>::iterator i=P.begin();i!=P.end() && cnt<=L;++i,++cnt) sum-=*i;
        cout<<sum<<"\n";
    }
    return 0;
}
