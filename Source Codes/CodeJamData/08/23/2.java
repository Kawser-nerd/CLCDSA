import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;
//1.6
public class C implements Runnable
{
	static final String NAME = "c-large";

	int K;

	public int calc(int v)
	{
		int cards = K;
		for (int i = 1; i <= K; i++)
		{
			int j = ((i - 1) % cards) + 1;
			if (j == v)
			{
				return i;
			}
			if (j < v)
			{
				v -= j;
			}
			else
			{
				v = cards + v - j;
			}
			cards--;
		}
		return 0;
	}
	public void solve() throws Exception
	{
		int ntest = Integer.parseInt(readWord());
		for (int test = 1; test <= ntest; test++)
		{
			stdout.write("Case #" + test + ":");
			K = Integer.parseInt(readWord());
			int n = Integer.parseInt(readWord());
			for (int i = 0; i < n; i++)
			{
				int v = Integer.parseInt(readWord());
				stdout.write(" " + calc(v));
			}
			stdout.write("\n");
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
		new Thread(new C()).start();
	}
}
