import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;

public class B
{
	final static String problem = "b-large";
	BufferedReader in;
	BufferedWriter out;

	HashMap<String, Integer> color;
	ArrayList<int[]> map;
	int curColor;

	public int calc()
	{
		int ans = Integer.MAX_VALUE;
		for (int c1 = 0; c1 < curColor; c1++)
		{
			int[] a1 = map.get(c1);
			for (int c2 = 0; c2 < Math.max(1,c1); c2++)
			{
				int[] a2 = map.get(c2);
				main: for (int c3 = 0; c3 < Math.max(1,c2); c3++)
				{
					int[] a3 = map.get(c3);
					int start = 0;
					int curAns = 0;
					while (start < 10000)
					{
						int next = Math.max(Math.max(a1[start], a2[start]),
								a3[start]);
						if (next == 0)
						{
							continue main;
						}
						start = next;
						curAns++;
					}
					ans = Math.min(ans, curAns);
				}
			}
		}
		return ans;
	}

	public void solve() throws Exception
	{
		int cases = iread();
		for (int i = 1; i <= cases; i++)
		{
			int n = iread();
			color = new HashMap<String, Integer>();
			map = new ArrayList<int[]>();
			curColor = 0;
			for (int j = 0; j < n; j++)
			{
				String s = readWord();
				int a = iread() - 1;
				int b = iread();
				if (!color.containsKey(s))
				{
					color.put(s, curColor);
					map.add(new int[10000]);
					curColor++;
				}
				int ind = color.get(s);
				int[] data = map.get(ind);
				for (int k = a; k < b; k++)
				{
					data[k] = Math.max(data[k], b);
				}
			}
			int ans = calc();
			out.write("Case #" + i + ": ");
			if (ans == Integer.MAX_VALUE)
			{
				out.write("IMPOSSIBLE\n");
			} else
			{
				out.write(ans + "\n");
			}
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
			new B().run();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
