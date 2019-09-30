#include <iostream>
#include <string>
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
inline void solve()
{
  int n;
  cin>>n;
  string string_n = to_string(n);
  replace(ALL(string_n), '1', 'X');
  replace(ALL(string_n), '9', '1');
  replace(ALL(string_n), 'X', '9');
  cout<<string_n<<endl;
}
int main(int argc,char**argv)
{
  BEGIN
  solve();
  END
}