#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;


int tc, ntc;
int n, m;

bool valid(int y, int x)
{
	return (y>=0 && y<n && x>=0 && x<m);
}


char mm[16][16];

int sh[225][4];
int pout[512];

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int enc_wall(int y, int x, int d)
{
	int res = y;
	res = res*(m+1) + x;
	res = res*2 + d;
	return res;
}

void dec_wall(int v, int& y, int &x, int& d)
{
	d = v%2; v /= 2;
	x = v%(m+1); v/=(m+1);
	y = v;	
}

int enc_pos(int y, int x)
{
	return y*m + x;
}

void dec_pos(int v, int& y, int& x)
{
	x = v%m; v/=m;
	y = v;
}

void gen_shoot()
{
	int i, j, k;
	int cy, cx, wy, wx, wd;
	for (i=0; i<n; i++) for (j=0; j<m; j++) if (mm[i][j] == '.')
	{
		for (k=0; k<4; k++)
		{
			cy = i;
			cx = j;
			while (valid(cy,cx) && mm[cy][cx] != '#')
			{
				cy += dy[k];
				cx += dx[k];
			}
			
			if (k == 0)
			{
				wy = cy + 1;
				wx = cx;
				wd = 1;				
			}
			else if (k == 2)
			{
				wy = cy;
				wx = cx;
				wd = 1;
			}
			else if (k == 1)
			{
				wy = cy;
				wx = cx;
				wd = 0;
			}
			else if (k == 3)
			{
				wy = cy;
				wx = cx+1;
				wd = 0;
			}
			
			
			sh[enc_pos(i,j)][k] = enc_wall(wy,wx,wd);	
			cy -= dy[k];
			cx -= dx[k];

			pout[ enc_wall(wy,wx,wd) ] = enc_pos(cy, cx);
			
//			printf("%d %d %d : %d %d %d : %d %d -- %d\n",i,j,k,wy,wx,wd,cy,cx,enc_wall(wy,wx,wd));			
		}
	}
}

//////////////////////////////////////////////

struct tt
{
	int y, x;
	int p1, p2;
};


#define INF 100000000

int v[225][513][513];
int sy, sx, ey, ex;

list <tt> q;
int npos, nw;

void add(const tt& st, int front, int val)
{
	int p = enc_pos(st.y, st.x);
	if (!front)
	{				
		if (v[p][st.p1][st.p2] > val)
		{
			//printf("added1: %d %d %d\n",p,st.p1,st.p2);
			v[p][st.p1][st.p2] = val;
			q.push_back( st );
		}
	}
	else
	{
		if (v[p][st.p1][st.p2] > val)
		{
			//printf("added2: %d %d %d\n",p,st.p1,st.p2);
			v[p][st.p1][st.p2] = val;
			q.push_front( st );
		}
	}
}

tt do_move(tt st, int dir)
{
	tt res = st;
	res.y = st.y + dy[dir];
	res.x = st.x + dx[dir];
	if (valid(res.y,res.x) && mm[res.y][res.x] != '#') return res;
	
	if (st.p1 == nw-1 || st.p2 == nw-1)
	{
		res.y = -1;
		return res;
	}
	
	int wy, wx, wd;
	dec_wall( st.p1, wy, wx, wd);
	
	if (wd == 0)
	{
		if (dir == 0 || dir == 2) {res.y = -1; return res;}
		int yy = st.y;
		int xx = max(st.x, res.x);		
		if (yy != wy || xx != wx) {res.y = -1; return res;}		
		dec_pos( pout[st.p2], res.y, res.x );
		return res;
	}
	else
	{
		if (dir == 1 || dir == 3) {res.y = -1; return res;}
		int yy = max(st.y, res.y);
		int xx = st.x;
		if (yy != wy || xx != wx) {res.y = -1; return res;}		
		dec_pos( pout[st.p2], res.y, res.x );		
	}
	
}

void debug(tt t, int v)
{
	int wy1, wx1, wd1;
	int wy2, wx2, wd2;
	if (t.p1 == nw-1) wy1 = wx1 = wd1 = -1;
	else dec_wall(t.p1, wy1, wx1, wd1);
	
	if (t.p2 == nw-1) wy2 = wx2 = wd2 = -1;
	else dec_wall(t.p2, wy2, wx2, wd2);
	
	printf("%d %d : %d %d %d : %d %d %d : %d\n",t.y,t.x,wy1,wx1,wd1,wy2,wx2,wd2, v);
}

int bfs()
{
	npos = n*m;
	nw = (n+1)*(m+1)*2+1;
	int i, j, k;
	for (i=0; i<npos; i++)
		for (j=0; j<nw; j++)
			for (k=0; k<nw; k++)
				v[i][j][k] = INF;
				
	q.clear();
	tt cur, nex;
	cur.y = sy;
	cur.x = sx;
	cur.p1 = nw-1;
	cur.p2 = nw-1;
		
	int cval;
	add(cur, 0, 0);
	int nw;
	
	int pos;
	
	while (!q.empty())
	{
		cur = q.front();
		q.pop_front();
		
		pos = enc_pos(cur.y,cur.x);
		cval = v[pos][cur.p1][cur.p2];
		//debug( cur, cval );
		
		if (cur.y == ey && cur.x == ex) return cval;
			
		
		// move
		for (i=0; i<4; i++)
		{
			nex = do_move(cur, i);
			if (nex.y == -1) continue;
			
			add(nex, 0, cval+1);
		}
		
		// shoot yellow
		for (i=0; i<4; i++)
		{
			nw = sh[ pos ][i];
			if (nw == cur.p2) continue;
			
			nex = cur;
			nex.p1 = nw;
			add(nex, 1, cval);
		}
		
		// shoot blue
		for (i=0; i<4; i++)
		{
			nw = sh[ pos ][i];
			if (nw == cur.p1) continue;
			
			nex = cur;
			nex.p2 = nw;
			add(nex, 1, cval);
		}
	}
	
	
	return INF;
}

int main()
{
	scanf("%d",&ntc);
	int i, j;
	int res;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d",&n, &m);
		for (i=0; i<n; i++) scanf("%s",mm[i]);
		for (i=0; i<n; i++) for (j=0; j<m; j++)
		{
			if (mm[i][j] == 'O') 
			{
				mm[i][j] = '.';
				sy = i;
				sx = j;
			}
			if (mm[i][j] == 'X')
			{
				mm[i][j] = '.';
				ey = i;
				ex = j;
			}
		}
		
		gen_shoot();
		
		res = bfs();
		
		printf("Case #%d: ",tc);
		if (res >= INF) printf("THE CAKE IS A LIE\n");
		else printf("%d\n",res);
		
		fprintf(stderr,"Case #%d: ",tc);
		if (res >= INF) fprintf(stderr,"THE CAKE IS A LIE\n");
		else fprintf(stderr,"%d\n",res);
		
	}
}