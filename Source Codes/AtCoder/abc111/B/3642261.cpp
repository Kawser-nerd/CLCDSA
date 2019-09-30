#include <iostream>
using namespace std;
#define BEGIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define END return EXIT_SUCCESS;
#define FOR(I,A,B) for(int (I)=(A);(I)<(B);++(I))
#define ALL(C) (C).begin(),(C).end()
#define INPUT(P) cin>>(P);
#define INPUT2(P1,P2) cin>>(P1)>>(P2);
#define INPUT3(P1,P2,P3) cin>>(P1)>>(P2)>>(P3);
#define INPUTS(I,A,B,V) FOR(I,A,B)cin>>V[I];
#define OUTPUT(P) cout<<P<<endl;
#define OUTPUTS(I,A,B,V) FOR(I,A,B)cout<<V[i]<<endl;
typedef long long ll;
const double INF = 1e9;
int N;
inline void solve()
{
  cin>>N;
  int num[9] = {111,222,333,444,555,666,777,888,999};
  FOR(i,0,9) {
    if (N <= num[i]) {
      cout<<num[i]<<endl;
      break;
    }
  }
}
int main(int argc,char**argv)
{
  BEGIN
  solve();
  END
}