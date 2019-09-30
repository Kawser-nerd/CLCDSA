#include <string>
#include <iostream>

using namespace std;

char board[15][15];
int R, C, kR, kC;

void read_data()
{
  cin >> R >> C;
  string s;
  for ( int r=0; r<R ; ++r )
  {
    cin >> s;
    for ( int c=0; c<C; ++c )
    {
      if ( s[c] == 'K' )
      {
        kR = r; kC = c;
        s[c] = '.';
      }
      board[r][c] = s[c];
    }
  }
}


int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int score(int r, int c, unsigned visited)
{
  for ( int d=0; d<8; ++d )
  {
    int nr = r + dr[d], nc = c + dc[d];
    if ( 0 <= nr and nr < R and 0 <= nc and nc < C and board[nr][nc] != '#' 
        and (visited & (1<<(nr*C + nc))) == 0)
    {
      int tmp_sc = score(nr, nc, visited | (1<<(nr*C + nc)));
      if ( not tmp_sc )
        return 1;
    }
  }
  return 0;
}


int main()
{
  int N;
  cin >> N;
  for ( int nc=1; nc <= N; ++nc )
  {
    read_data();
    int sc = score(kR, kC, 1 << (kR*C + kC));
    if ( sc )
      cout << "Case #" << nc << ": A" << endl;
    else
      cout << "Case #" << nc << ": B" << endl;
  }
  return 0;
}
