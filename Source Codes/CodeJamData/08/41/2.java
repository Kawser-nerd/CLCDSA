import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;

//java 1.6
public class A implements Runnable
{
	static final String NAME = "a-large";
	int m;

	int v;

	int[] values;

	int[] gates;

	int[] changable;

	public static final int AND = 1;

	public static final int OR = 0;

	private void calcValues()
	{
		for (int i = m / 2 - 1; i >= 0; i--)
		{
			if (gates[i] == OR)
			{
				values[i] = values[2 * i + 1] | values[2 * i + 2];
			}
			else
			{
				values[i] = values[2 * i + 1] & values[2 * i + 2];
			}
		}
	}
	
	public int rec0(int node)
	{
		if (values[node] == v)
		{
			return 0;
		}
		if (node >= m / 2)
		{
			return -1;
		}
		int v1 = rec0(2 * node + 1);
		int v2 = rec0(2 * node + 2);
		int orvalue;
		if (v1 == -1 || v2 == -1)
		{
			orvalue = -1;
		}
		else
		{
			orvalue = v1 + v2;
		}
		int andvalue = best(v1, v2);
		if (gates[node] == OR)
		{
			if (changable[node] > 0)
			{
				return best(orvalue, add1(andvalue));
			}
			return orvalue;
		}
		if (changable[node] > 0)
		{
			return best(andvalue, add1(orvalue));
		}
		return andvalue;
	}

	public int best(int v1, int v2)
	{
		if (v1 == -1)
		{
			return v2;
		}
		if (v2 == -1)
			return v1;
		return Math.min(v1, v2);
	}

	public int add1(int v)
	{
		if (v == -1)
			return -1;
		return v + 1;
	}

	public int rec1(int node)
	{
		if (values[node] == v)
		{
			return 0;
		}
		if (node >= m / 2)
		{
			return -1;
		}
		int v1 = rec1(2 * node + 1);
		int v2 = rec1(2 * node + 2);
		int orvalue = best(v1, v2);
		int andvalue;
		if (v1 == -1 || v2 == -1)
		{
			andvalue = -1;
		}
		else
		{
			andvalue = v1 + v2;
		}
		if (gates[node] == OR)
		{
			if (changable[node] > 0)
			{
				return best(orvalue, add1(andvalue));
			}
			return orvalue;
		}
		if (changable[node] > 0)
		{
			return best(andvalue, add1(orvalue));
		}
		return andvalue;
	}

	public void solve() throws Exception
	{
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			m = Integer.parseInt(readWord());
			values = new int[m];
			gates = new int[m];
			changable = new int[m];
			v = Integer.parseInt(readWord());
			for (int i = 0; i < m / 2; i++)
			{
				gates[i] = Integer.parseInt(readWord());
				changable[i] = Integer.parseInt(readWord());
			}
			for (int i = m / 2; i < m; i++)
			{
				values[i] = Integer.parseInt(readWord());
			}
			calcValues();
			int ans = v == 1 ? rec1(0) : rec0(0);
			String s = ans == -1 ? "IMPOSSIBLE" : ans + "";
			stdout.write("Case #" + test + ": " + s + "\n");
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
		new Thread(new A()).start();
	}
}
