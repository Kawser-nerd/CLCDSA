import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;

//1.6
public class B implements Runnable
{
	static final String NAME = "b-large";

	int[] primes;

	int[] plist;

	int np;

	public void init()
	{
		primes = new int[1000010];
		plist = new int[1000010];
		np = 0;
		for (int i = 2; i < 1000010; i++)
		{
			if (primes[i] != 0)
			{
				continue;
			}
			plist[np] = i;
			np++;
			if (i > 1000)
			{
				continue;
			}
			for (int j = i * i; j < 1000010; j += i)
			{
				primes[j] = 1;
			}
		}
	}
	
	int[] parent;

	int[] level;

	int getParent(int v)
	{
		if (parent[v] == v)
		{
			return v;
		}
		int res = getParent(parent[v]);
		parent[v] = res;
		return res;
	}

	void union(int v1, int v2)
	{
		int p1 = getParent(v1);
		int p2 = getParent(v2);
		if (p1 == p2)
		{
			return;
		}
		if (level[p1] < level[p2])
		{
			parent[p1] = p2;
		}
		else if (level[p1] > level[p2])
		{
			parent[p2] = p1;
		}
		else
		{
			parent[p2] = p1;
			level[p1]++;
		}
	}

	public void solve() throws Exception
	{
		init();
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			long a = Long.parseLong(readWord());
			long b = Long.parseLong(readWord());
			long p = Long.parseLong(readWord());
			int d = (int) (b - a + 1);
			parent = new int[d];
			level = new int[d];
			for (int i = 0; i < d; i++)
			{
				parent[i] = i;
			}
			for (int i = 0; i < np; i++)
			{
				int pp = plist[i];
				if (pp < p)
				{
					continue;
				}
				int t = (int) (a % pp);
				if (t > 0)
				{
					t = pp - t;
				}
				for (int j = t + pp; j < d; j += pp)
				{
					union(t, j);
				}
			}
			int ans = 0;
			for (int i = 0; i < d; i++)
			{
				if (parent[i] == i)
				{
					ans++;
				}
			}
			stdout.write("Case #" + test + ": " + ans + "\n");
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
			b.append((char) c);
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
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		try
		{
			Locale.setDefault(Locale.US);
		}
		catch (Throwable e)
		{
		}
		new Thread(new B()).start();
	}
}
