import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;

//java 1.6
public class B implements Runnable
{
	static final String NAME = "b-large";

	public void solve() throws Exception
	{
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			long n = Long.parseLong(readWord());
			long m = Long.parseLong(readWord());
			long a = Long.parseLong(readWord());
			if (a > n * m)
			{
				stdout.write("Case #" + test + ": " + "IMPOSSIBLE\n");
				continue;
			}
			long s = a % n;
			if (s == 0)
			{
				stdout.write("Case #" + test + ": " + "0 0 " + n + " " + 0 + " " + n + " "
					+ (a / n) + "\n");
			}
			else
			{
				stdout.write("Case #" + test + ": " + "0 0 " + n + " " + 1 + " " + (n - s) + " "
					+ (a / n + 1) + "\n");
			}
			// stdout.write("Case #" + test + ": " + null + "\n");
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
		new Thread(new B()).start();
	}
}
