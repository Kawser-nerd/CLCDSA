const int maxp = 100000;
#include <pe>
static inline int Rint()
{
    struct X{ int dig[256]; X(){
    for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
    }};
    static     X fuck;int s = 1, v = 0, c;
    for (;!fuck.dig[c = getchar()];);
    if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
    for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
    return s ? v : -v;
}
typedef set<vector<pair<int, int> > > SHAPE;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int his[10][2];
int visited[15][15];
int DEST;
set<SHAPE> shapes[10];
void  regular(vector<pair<int, int> >& points)
{
  int minx = 100, miny = 100;
  for (auto item: points)
  {
    cmin(minx, item.first);
    cmin(miny, item.second);
  }
  /*
  for (int i = 0; i < DEST; ++i)
  {
    if (his[i][0] < minx) minx = his[i][0];
    if (his[i][1] < miny) miny = his[i][1];
  }*/
  for (auto& item : points)
  item.first -= minx, item.second -= miny;
  sort(all(points));
}

void  regular1(vector<pair<int, int> >& points)
{
  sort(all(points));
  int a = points[0].first;
  int b = points[0].second;
  for (auto& item : points)
  item.first -= a, item.second -= b;
}

void  rotate_left(vector<pair<int, int> >& points)
{
  int minx = 100, miny = 100;
  int maxx = -100, maxy = -100;
  for (auto item: points)
  {
    cmin(minx, item.first);
    cmin(miny, item.second);
    cmax(maxx, item.first);
    cmax(maxy, item.second);
  }
  for (auto& item: points)
  {
    int newx = maxy - item.second;
    int newy = item.first;
    item.first = newx;
    item.second = newy;
  }
}

void flip(vector<pair<int, int> >& points)
{
  int minx = 100, miny = 100;
  int maxx = -100, maxy = -100;
  for (auto item: points)
  {
    cmin(minx, item.first);
    cmin(miny, item.second);
    cmax(maxx, item.first);
    cmax(maxy, item.second);
  }
  for (auto& item: points)
  {
    item.first = maxx - item.first;
  }
}
void flip1(vector<pair<int, int> >& points)
{
  int minx = 100, miny = 100;
  int maxx = -100, maxy = -100;
  for (auto item: points)
  {
    cmin(minx, item.first);
    cmin(miny, item.second);
    cmax(maxx, item.first);
    cmax(maxy, item.second);
  }
  for (auto& item: points)
  {
    item.second = maxy - item.second;
  }
}

set<vector<pair<int, int> > > make_shape(vector<pair<int, int> > points)
{
  set<vector<pair<int, int> > > all;
  regular(points);
  for (int i = 0; i < 4; ++i)
  {
    rotate_left(points);
    regular(points);
    all.insert(points);
  }
  flip(points);
  regular(points);
  for (int i = 0; i < 4; ++i)
  {
    rotate_left(points);
    regular(points);
    all.insert(points);
  }
  flip(points);
  regular(points);
  flip1(points);
  regular(points);
  for (int i = 0; i < 4; ++i)
  {
    rotate_left(points);
    regular(points);
    all.insert(points);
  }
  return all;
}

void dfs1(int x, int y, int used)
{
  //cerr << x << " " << y << " " << used << " " << DEST << endl;
  for (int orz = 0; orz < used; ++orz)
  for (int i = 0; i < 4; ++i)
  {
    int nx = his[orz][0] + dir[i][0];
    int ny = his[orz][1] + dir[i][1];
    if (visited[nx][ny]) continue;
    his[used][0] = nx;
    his[used][1] = ny;
    visited[nx][ny] = 1;
    if (used + 1 == DEST)
    {
      vector<pair<int, int> > vec;
      for (int i = 0; i < DEST; ++i)
      {
        vec.push_back({his[i][0], his[i][1]});
      }
      shapes[DEST].insert(make_shape(vec));
    }
    else
    {
      dfs1(nx, ny, used+1);
    }
    visited[nx][ny] = 0;
  }
}




int mat[100][100];
int R, C;
set<int64> pre[10][100][100];
void dfs(int x, int y, int64 flag)
{
  if (x == R && y == 0)
  {
    pre[DEST][R][C].insert(flag);
    return;
  }
  if (y == C)
  {
    dfs(x+1, 0, flag);
    return;
  }
  if (mat[x][y])
  {
    dfs(x, y+1, flag);
    return;
  }
  int shapeid = 0;
  for (auto& shape: shapes[DEST])
  {
    for (auto& item: shape)
    {
      int ok = 1;
      for (auto p: item)
      {
        const int cx = x + p.first;
        const int cy = y + p.second;
        if (cx >= R || cy >= C || cx < 0 || cy < 0)
        {
          ok = 0;
          break;
        }
        if (mat[cx][cy])
        {
          ok = 0;
          break;
        }
      }
      if (!ok) continue;
      
      for (auto p: item)
      {
        const int cx = x + p.first;
        const int cy = y + p.second;
        mat[cx][cy] = 1;
      }
      dfs(x, y+1, flag | 1LL << shapeid);
      for (auto p: item)
      {
        const int cx = x + p.first;
        const int cy = y + p.second;
        mat[cx][cy] = 0;
      }
    }
    ++shapeid;
  }
}
void init()
{
  for (DEST = 2; DEST <= 7; ++DEST)
  {
    his[0][0] = his[0][1] = 6;
    visited[6][6] = 1;
    dfs1(6, 6, 1);
    
    set<SHAPE> temp;
    for (auto& shape: shapes[DEST])
    {
      set<vector<pair<int, int> > > t;
      for (auto& item: shape)
      {
        auto t1 = item;
        regular1(t1);
        t.insert(t1);
        if (DEST == 2)
        {
          for (auto i : t1)
          cerr << i.first << "," << i.second << " ";
          cerr << endl;
        }
      }
      temp.insert(t);
    }
    shapes[DEST].swap(temp);
    cerr << shapes[DEST].size() << endl;
  }
  for (DEST = 2; DEST <= 6; ++DEST)
  for (R = 1; R <= 4; ++R)
  for (C = R; C <= 4; ++C)
  {
    int total = R*C;
    if (total % DEST) continue;
    dfs(0, 0, 0);
  }
}
int can_richard_win(int x, int r, int c)
{
  int total = r * c;
  if (total % x) return 1;
  if (x == 1) return 0;
  if (x == 2)
  {
    //if (total % 2 == 0) return 0;
    //else return 1;
  }
  if (r > c) swap(r, c);
  if (pre[x][r][c].empty()) return 1;
  const int n = shapes[x].size();
  for (int i = 0; i < n; ++i)
  {
    int ok = 1;
    for (auto iter: pre[x][r][c])
    if (iter & (1LL << i)) {ok = 0; break;}
    if (ok) return 1;
  }
  return 0;
}

int main()
{
  init();
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    int x = Rint(), r = Rint(), c = Rint();
    int ok = can_richard_win(x, r, c);
    if (ok) printf("Case #%d: RICHARD\n", id);
    else printf("Case #%d: GABRIEL\n", id);
  }
  return 0;
}