#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int mem[1<<10][11];

char room[10][10];
int R, C;

int max_students(int bad, int row)
{
  int &r = mem[bad][row];
  if ( r >= 0 )
    return r;
  int best = 0;
  for ( int mask=0; mask < (1<<C); ++mask )
  {
    bool good = true;
    for ( int k=0; k<C; ++k )
      if ( mask&(1<<k) )
      {
        if ( (bad&(1<<k)) or room[row][k]=='x' )
        {
          good = false;
          break;
        }
        if ( k > 0 and (mask&(1<<(k - 1))) )
        {
          good = false;
          break;
        }
        if ( k < C - 1 and (mask&(1<<(k + 1))) )
        {
          good = false;
          break;
        }
      }
    if ( good )
    {
      int cs = 0, new_bad = 0;
      for ( int k=0; k<C; ++k )
        if ( mask&(1<<k) )
        {
          ++cs;
          if ( k > 0 )
            new_bad |= (1<<(k - 1));
          if ( k < C - 1 )
            new_bad |= (1<<(k + 1));
        }
      if ( row < R - 1)
        cs += max_students(new_bad, row + 1);
      best = best >= cs ? best : cs;
    }
  }
  r = best;
  return best;
}


int read_case()
{
  cin >> R >> C;
  memset(mem, -1, sizeof(mem));
  for ( int r=0; r<R; ++r )
  {
    string cr;
    cin >> cr;
    for ( int c=0; c<C; ++c )
      room[r][c] = cr[c];
  }
  return max_students(0, 0);
}


int main()
{
  int NC;
  cin >> NC;
  for ( int nc=1; nc<=NC; ++nc )
  {
    int res = read_case();
    cout << "Case #" << nc << ": " << res << endl;
  }
  return 0;
}
