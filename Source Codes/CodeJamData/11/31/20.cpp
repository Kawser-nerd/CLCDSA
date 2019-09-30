#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int T,N,M;
char A[55][55];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin>>T;
    for (int t=1;t<=T;++t) {
        cout<<"Case #"<<t<<":\n";
        cin>>N>>M;
        memset(A,0,sizeof(A));
        for (int i=1;i<=N;++i)
            for (int j=1;j<=M;++j)
                scanf(" %c",&A[i][j]);
        bool flag=true;
        while (1) {
              bool fns=false;
              for (int i=1;i<=N;++i)
                  for (int j=1;j<=M;++j) 
                      if (A[i][j]=='#') {
                         fns=true;
                         if (A[i+1][j]!='#' || A[i][j+1]!='#' || A[i+1][j+1]!='#') flag=false;
                         else {A[i][j]='/';A[i][j+1]='\\';A[i+1][j]='\\';A[i+1][j+1]='/';}
                      }
              if (!flag || !fns) break;
        }
        if (!flag) cout<<"Impossible\n";
        else for (int i=1;i<=N;++i) {
                 for (int j=1;j<=M;++j) cout<<A[i][j];
                 cout<<"\n";
        }
    }
    return 0;
}
