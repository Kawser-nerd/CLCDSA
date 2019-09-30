import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;

// 1.6
public class B implements Runnable
{
	static final String NAME = "b-large";

	String opt;

	int[] stats;

	String n;

	int len;

	public void calcOpt(int place, boolean flag, String s)
	{
		if (place == len)
		{
			if (!flag)
			{
				opt = s;
			}
			return;
		}
		for (int i = 0; i < 10; i++)
		{
			if (opt != null)
			{
				return;
			}
			if (stats[i] == 0)
			{
				continue;
			}
			if (flag && i < (n.charAt(place) - '0'))
			{
				continue;
			}
			stats[i]--;
			calcOpt(place + 1, flag & i == (n.charAt(place) - '0'), s + i);
			stats[i]++;
		}
	}

	public void solve() throws Exception
	{
		int tests = Integer.parseInt(readWord());
		for (int test = 1; test <= tests; test++)
		{
			n = readWord();
			len = n.length();
			stats = new int[10];
			for (int i = 0; i < len; i++)
			{
				stats[n.charAt(i) - '0']++;
			}
			opt = null;
			calcOpt(0, true, "");
			if (opt == null)
			{
				n = "0" + n;
				len++;
				stats[0]++;
				calcOpt(0, true, "");
			}
			stdout.write("Case #" + test + ": " + opt + "\n");
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
