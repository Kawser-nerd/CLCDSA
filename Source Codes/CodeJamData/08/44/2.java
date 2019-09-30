import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;

//java 1.6
public class D implements Runnable
{
	static final String NAME = "d-large";
	int k;

	String s;
	int[][] graph1;

	int[][] graph2;

	public void transform()
	{
		int nk = s.length() / k;
		graph1 = new int[k][k];
		graph2 = new int[k][k];
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				for (int t = 0; t < nk; t++)
				{
					if (s.charAt(t * k + i) != s.charAt(t * k + j))
					{
						graph1[i][j]++;
					}
				}
				for (int t = 0; t < nk - 1; t++)
				{
					if (s.charAt(t * k + j) != s.charAt(t * k + k + i))
					{
						graph2[i][j]++;
					}
				}
			}
		}
	}
	int[][][] table;

	int ans;

	public void dyn()
	{
		table = new int[1 << k][k][k];
		for (int i = 1; i < 1 << k; i++)
		{
			int count = Integer.bitCount(i);
			if (Integer.bitCount(i) == 1)
			{
				continue;
			}
			for (int j1 = 0; j1 < k; j1++)
			{
				if ((i & (1 << j1)) == 0)
				{
					continue;
				}
				for (int j2 = j1 + 1; j2 < k; j2++)
				{
					if (j2 == j1 || (i & (1 << j2)) == 0)
					{
						continue;
					}
					if (count == 2)
					{
						table[i][j1][j2] = graph1[j1][j2];
						table[i][j2][j1] = graph1[j1][j2];
						continue;
					}
					int min = Integer.MAX_VALUE;
					for (int j3 = 0; j3 < k; j3++)
					{
						if (j3 == j1 || j3 == j2 || (i & (1 << j3)) == 0)
						{
							continue;
						}
						min = Math.min(min, table[i - (1 << j2)][j1][j3] + graph1[j3][j2]);
					}
					table[i][j1][j2] = min;
					table[i][j2][j1] = min;
				}
			}
		}
		ans = Integer.MAX_VALUE;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (j == i)
				{
					continue;
				}
				ans = Math.min(ans, table[(1 << k) - 1][i][j] + graph2[i][j]);
			}
		}
	}
	public void solve() throws Exception
	{
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			k = Integer.parseInt(readWord());
			s = readWord();
			transform();
			dyn();
			stdout.write("Case #" + test + ": " + (ans + 1) + "\n");
		}
	}

	static BufferedReader stdin;
	static BufferedWriter stdout;

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
			solve();
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
		new Thread(new D()).start();
	}
}
