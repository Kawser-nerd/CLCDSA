#include <iostream>

using namespace std;


inline long ar(long x1, long y1, long x2, long y2)
{
  return x1*y2 - x2*y1;
}


int X1, Y1, X2, Y2;

bool brute(int N, int M, int A)
{
  for ( int x1=0; x1<=N; ++x1 )
    for ( int y1=0; y1<=M; ++y1 )
      for ( int x2=0; x2<=N; ++x2 )
        for ( int y2=0; y2<=M; ++y2 )
        {
          long a = ar(x1, y1, x2, y2);
          if ( a == A or a == -A )
          {
            X1 = x1; Y1 = y1;
            X2 = x2; Y2 = y2;
            return true;
          }
        }
  return false;
}


int main()
{
  int C;
  cin >> C;
  for ( int nc=1; nc<=C; ++nc )
  {
    int N, M, A;
    cin >> N >> M >> A;
    if ( brute(N, M, A) )
      cout << "Case #" << nc << ": 0 0 " << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2 << endl;
    else
      cout << "Case #" << nc << ": IMPOSSIBLE" << endl;
  }
  return 0;
}
