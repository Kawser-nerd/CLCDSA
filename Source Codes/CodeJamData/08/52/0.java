import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Locale;

//java 1.6
public class B implements Runnable
{
	static final String NAME = "b-small0";
	int r, c;

	int[][] field;

	int sx, sy;

	int fx, fy;

	final static String IMPOSSIBLE = "THE CAKE IS A LIE";
	HashSet<Integer> set;

	int[] dx = new int[] { -1, 1, 0, 0 };

	int[] dy = new int[] { 0, 0, -1, 1 };
	public int encode(int x, int y)
	{
		return x * c + y;
	}

	public int encodeAll(int x, int y, int dir1, int px1, int py1, int dir2, int px2, int py2)
	{
		return encode(x, y) + 300
			* (encode(px1, py1) + 300 * dir1 + 1500 * (encode(px2, py2) + 300 * dir2));
	}

	int[][][] fieldx;

	int[][][] fieldy;

	public void initPortals()
	{
		fieldx = new int[r][c][4];
		fieldy = new int[r][c][4];
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					int curx = i;
					int cury = j;
					while (curx + dx[k] >= 0 && curx + dx[k] < r && cury + dy[k] >= 0
						&& cury + dy[k] < c && field[curx + dx[k]][cury + dy[k]] == 0)
					{
						curx += dx[k];
						cury += dy[k];
					}
					fieldx[i][j][k] = curx;
					fieldy[i][j][k] = cury;
				}
			}
		}
	}
	public int calc()
	{
		initPortals();
		HashSet<Integer> cur = new HashSet<Integer>();
		HashSet<Integer> next = new HashSet<Integer>();
		int start = encodeAll(sx, sy, 4, 0, 0, 4, 0, 0);
		cur.add(start);
		int res = 0;
		while (true)
		{
			res++;
			for (Integer sost : cur)
			{
				int v = sost;
				int xy = v % 300;
				int x = xy / c;
				int y = xy % c;
				v = v / 300;
				xy = v % 1500;
				int dir1 = xy / 300;
				xy = xy % 300;
				int px1 = xy / c;
				int py1 = xy % c;
				v = v / 1500;
				int dir2 = v / 300;
				v = v % 300;
				int px2 = v / c;
				int py2 = v % c;
				for (int blue=0;blue<=4;blue++)
				{
					int dirBlue;
					int pxBlue;
					int pyBlue;
					if (blue==4)
					{
						dirBlue=dir1;
						pxBlue=px1;
						pyBlue=py1;
					}else
					{
						dirBlue=blue;
						pxBlue=fieldx[x][y][blue];
						pyBlue=fieldy[x][y][blue];
					}
					for (int yellow=0;yellow<=4;yellow++)
					{
						int dirYellow;
						int pxYellow;
						int pyYellow;
						if (yellow==4)
						{
							dirYellow=dir2;
							pxYellow=px2;
							pyYellow=py2;
						}else
						{
							dirYellow=yellow;
							pxYellow=fieldx[x][y][yellow];
							pyYellow=fieldy[x][y][yellow];
						}
						for (int s=0;s<4;s++)
						{
							int vx=x;
							int vy=y;
							if (x == pxBlue && y == pyBlue && s == dirBlue && dirYellow != 4)
							{
								vx=pxYellow;
								vy=pyYellow;
							}
							else if (x == pxYellow && y == pyYellow && s == dirYellow
								&& dirBlue != 4)
							{
								vx=pxBlue;
								vy=pyBlue;
							}else if (x+dx[s]>=0 && x+dx[s]<r && y+dy[s]>=0 && y+dy[s]<c && field[x+dx[s]][y+dy[s]]==0)
							{
								vx=x+dx[s];
								vy=y+dy[s];
							}
							if (vx == fx && vy == fy)
							{
								return res;
							}
							int newv=encodeAll(vx,vy,dirBlue,pxBlue,pyBlue,dirYellow,pxYellow,pyYellow);
							if (!set.contains(newv))
							{
								set.add(newv);
								next.add(newv);
							}
						}
					}
				}
			}
			if (next.size() == 0)
			{
				return -1;
			}
			cur = next;
			next = new HashSet<Integer>();
		}
		// return res;
	}
	public String solve() throws Exception
	{
		r = Integer.parseInt(readWord());
		c = Integer.parseInt(readWord());
		field = new int[r][c];
		sx = -1;
		sy = -1;
		fx = -1;
		fy = -1;
		for (int i = 0; i < r; i++)
		{
			String s = readWord();
			for (int j = 0; j < c; j++)
			{
				if (s.charAt(j) == '#')
				{
					field[i][j] = 1;
				}
				if (s.charAt(j) == 'O')
				{
					sx = i;
					sy = j;
				}
				if (s.charAt(j) == 'X')
				{
					fx = i;
					fy = j;
				}
			}
		}
		set = new HashSet<Integer>();
		int res = calc();
		if (res < 0)
			return IMPOSSIBLE;
		return res + "";
	}
	public void init()
	{

	}
	String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
		while (true)
		{
			c = stdin.read();
			if (c < 0)
			{
				return "";
			}
			if (c > 32)
			{
				break;
			}
		}
		while (true)
		{
			b.append((char)c);
			c = stdin.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}
	public void run()
	{
		try
		{
			stdin = new BufferedReader(new FileReader(NAME + ".in"));
			stdout = new BufferedWriter(new FileWriter(NAME + ".out"));
			init();
			int ntest = Integer.parseInt(readWord());
			for (int test = 1; test <= ntest; test++)
			{
				stdout.write("Case #" + test + ": " + solve() + "\n");
			}
			stdout.close();
			stdin.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	public static void main(String[] args)
	{
		try
		{
			Locale.setDefault(Locale.US);
		} catch (Throwable e)
		{
		}
		new Thread(new B()).start();
	}
	static BufferedReader stdin;
	static BufferedWriter stdout;
	int test;
}
