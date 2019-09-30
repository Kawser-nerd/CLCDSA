import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class C
{
	final static String problem = "c-large";
	final static long prime = 1000000009L;
	BufferedReader in;
	BufferedWriter out;
	int n;
	long k;
	long ans;
	ArrayList<Integer>[] edges;
	int[] degs;

	public void solve() throws Exception
	{
		int cases = iread();
		for (int test = 1; test <= cases; test++)
		{
			n = iread();
			k = lread();
			ans = 1;
			edges = new ArrayList[n];
			for (int i = 0; i < n; i++)
			{
				edges[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n - 1; i++)
			{
				int x = iread() - 1;
				int y = iread() - 1;
				edges[x].add(y);
				edges[y].add(x);
			}
			degs = new int[n];
			for (int i = 0; i < n; i++)
			{
				degs[i] = edges[i].size();
			}
			calc2();
			//rec(0, -1, 1, 0);
			out.write("Case #" + test + ": " + ans + "\n");
		}
	}

	public boolean check(int v)
	{
		int count=0;
		for (int i=0;i<edges[v].size();i++)
		{
			if (degs[edges[v].get(i)]>1)
			{
				count++;
			}
		}
		return count<=1;
	}

	public int sumDegs(int v)
	{
		int ans=0;
		for (int i=0;i<edges[v].size();i++)
		{
			ans+=degs[edges[v].get(i)];
		}
		return ans;
	}

	public void calc2()
	{
		main: for (int iter=0;iter<n-1;iter++)
		{
			for (int i=0;i<n;i++)
			{
				if (degs[i]==1)
				{
					int next=edges[i].get(0);
					if (check(next))
					{
						int sum=sumDegs(next)-1;
						degs[i]--;
						degs[next]--;
						edges[next].remove(new Integer(i));
						if (k<sum)
						{
							ans=0;
						}else
						{
							ans*=k-sum;
							ans=ans%prime;
						}
						continue main;
					}
				}
			}
		}
	}

	public void rec(int cur, int prev, int dprev, int dprev1)
	{
		for (int i = 0; i < edges[cur].size(); i++)
		{
			int next = edges[cur].get(i);
			if (next != prev)
			{
				rec(next, cur, degs[cur], dprev);
				degs[cur]--;
			}
		}
		if (cur == 0)
		{
			return;
		}
		if (k < dprev + dprev1 - 2)
		{
			ans *= 0;
		} else
		{
			System.out.println(cur+" "+dprev+" "+dprev1+" "+(k-dprev-dprev1+2));
			ans *= k - dprev - dprev1 + 2;
			ans = ans % prime;
		}
	}

	public int iread() throws Exception
	{
		return Integer.parseInt(readWord());
	}

	public long lread() throws Exception
	{
		return Long.parseLong(readWord());

	}
	public double dread() throws Exception
	{
		return Double.parseDouble(readWord());
	}

	public String readWord() throws Exception
	{
		int c;
		StringBuilder b = new StringBuilder();
		while (true)
		{
			c = in.read();
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
			c = in.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	public void run() throws Exception
	{
		in = new BufferedReader(new FileReader(problem + ".in"));
		out = new BufferedWriter(new FileWriter(problem + ".out"));
		solve();
		out.flush();
	}

	public static void main(String[] args)
	{
		try
		{
			new C().run();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
