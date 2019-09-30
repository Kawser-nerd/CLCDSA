import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Locale;

//java 1.6
public class C implements Runnable
{
	static final String NAME = "c-large";
	int n, m;

	int[][] field;
	int[][] ind;

	int[] ns;

	int[][] neib1;

	int[][] neib2;

	int vs;
	int[] map;

	int[] rmap;

	int[] used;

	public boolean rec(int v)
	{
		if (used[v] > 0)
		{
			return false;
		}
		used[v] = 1;
		for (int i = 0; i < neib1[v].length; i++)
		{
			int w = neib1[v][i];
			if (rmap[w] < 0)
			{
				rmap[w] = v;
				return true;
			}
			int ww = rmap[w];
			if (rec(ww))
			{
				rmap[w] = v;
				return true;
			}
		}
		return false;
	}

	public int calcFlow()
	{
		map = new int[ns[0]];
		used = new int[ns[0]];
		rmap = new int[ns[1]];
		Arrays.fill(map, -1);
		Arrays.fill(rmap, -1);
		for (int i = 0; i < map.length; i++)
		{
			Arrays.fill(used, 0);
			rec(i);
		}
		int res = 0;
		for (int i = 0; i < rmap.length; i++)
		{
			if (rmap[i] >= 0)
			{
				res++;
			}
		}
		return res;
	}
	public void initGraph()
	{
		ns = new int[2];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (field[i][j] == 1)
				{
					ind[i][j] = ns[j % 2];
					ns[j % 2]++;
				}
			}
		}
		neib1 = new int[ns[0]][];
		neib2 = new int[ns[1]][];
		int[] temp = new int[6];
		int ntemp = 0;
		int[] dy = new int[] { -1, -1, -1, 1, 1, 1 };
		int[] dx = new int[] { -1, 0, 1, -1, 0, 1 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (field[i][j] == 1)
				{
					int v = ind[i][j];
					ntemp = 0;
					for (int k = 0; k < 6; k++)
					{
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii < 0 || ii >= n || jj < 0 || jj >= m)
						{
							continue;
						}
						if (field[ii][jj] == 1)
						{
							temp[ntemp] = ind[ii][jj];
							ntemp++;
						}
					}
					if (j % 2 == 0)
					{
						neib1[v] = new int[ntemp];
						System.arraycopy(temp, 0, neib1[v], 0, ntemp);
					}
					else
					{
						neib2[v] = new int[ntemp];
						System.arraycopy(temp, 0, neib2[v], 0, ntemp);
					}
				}
			}
		}
	}
	public String solve() throws Exception
	{
		n = Integer.parseInt(readWord());
		m = Integer.parseInt(readWord());
		field = new int[n][m];
		ind = new int[n][m];
		vs = 0;
		for (int i = 0; i < n; i++)
		{
			String s = readWord();
			for (int j = 0; j < m; j++)
			{
				if (s.charAt(j) == '.')
				{
					field[i][j] = 1;
					vs++;
				}
			}
		}
		initGraph();
		vs -= calcFlow();
		return vs + "";
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
		new Thread(new C()).start();
	}
	static BufferedReader stdin;
	static BufferedWriter stdout;
	int test;
}
