#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float m;
  cin >> m;

  float vv;
  if( m < 100 ) {
    vv = 0;
  }
  if( 100 <= m and m <= 5000 ) {
    vv = m / 1000. * 10.;
  }
  if( 6000 <= m and m <=30000 ) {
    vv = m / 1000. + 50.;
  }
  if( 35000 <= m and m <=70000 ) {
    vv = ( m / 1000. - 30. ) / 5. + 80.;
  }
  if( 70000 < m ) {
    vv = 89.;
  }
  cout << setfill( '0' ) << setw(2) << vv <<endl;

  return 0;
}