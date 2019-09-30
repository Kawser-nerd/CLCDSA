import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;
//1.6
public class A implements Runnable
{
	static final String NAME = "a-large";

	public void solve() throws Exception
	{
		int ntest = Integer.parseInt(readWord());
		for (int test = 0; test < ntest; test++)
		{
			int n = Integer.parseInt(readWord());
			long a = Integer.parseInt(readWord());
			long b = Integer.parseInt(readWord());
			long c = Integer.parseInt(readWord());
			long d = Integer.parseInt(readWord());
			long x0 = Integer.parseInt(readWord());
			long y0 = Integer.parseInt(readWord());
			long M = Integer.parseInt(readWord());
			// Set<Point> set = new HashSet<Point>();
			long[][] table = new long[3][3];
			for (int i = 0; i < n; i++)
			{
				Point p = new Point((int) x0, (int) y0);
				// if (set.contains(p))
				// {
				// continue;
				// }
				// set.add(p);
				table[(int) x0 % 3][(int) y0 % 3]++;
				x0 = (a * x0 + b) % M;
				y0 = (c * y0 + d) % M;
			}
			long ans = 0;
			for (int x1 = 0; x1 < 3; x1++)
			{
				for (int y1 = 0; y1 < 3; y1++)
				{
					long v1 = table[x1][y1];
					for (int x2 = 0; x2 < 3; x2++)
					{
						for (int y2 = 0; y2 < 3; y2++)
						{
							long v2 = table[x2][y2];
							int x3 = (6 - x1 - x2) % 3;
							int y3 = (6 - y1 - y2) % 3;
							long v3 = table[x3][y3];
							if (x1 == x2 && x2 == x3 && y1 == y2 && y2 == y3)
							{
								ans += v1 * (v1 - 1) * (v1 - 2);
								continue;
							}
							if (x1 == x2 && y1 == y2)
							{
								ans += v1 * (v1 - 1) * v3;
								continue;
							}
							if (x1 == x3 && y1 == y3)
							{
								ans += v1 * (v1 - 1) * v2;
								continue;
							}
							if (x2 == x3 && y2 == y3)
							{
								ans += v1 * v2 * (v2 - 1);
								continue;
							}
							ans += v1 * v2 * v3;
						}
					}
				}
			}
			stdout.write("Case #" + (test + 1) + ": " + (ans / 6) + "\n");
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
