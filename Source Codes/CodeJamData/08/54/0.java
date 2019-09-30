import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;

//java 1.6
public class D implements Runnable
{
	static final String NAME = "d-large";
	int h, w;

	int[] hr;

	int[] wr;
	public String solve() throws Exception
	{
		h = Integer.parseInt(readWord());
		w = Integer.parseInt(readWord());
		int r = Integer.parseInt(readWord());
		hr = new int[r];
		wr = new int[r];
		for (int i = 0; i < r; i++)
		{
			hr[i] = Integer.parseInt(readWord());
			wr[i] = Integer.parseInt(readWord());
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = i + 1; j < r; j++)
			{
				if (hr[j] + wr[j] < hr[i] + wr[i])
				{
					int t = hr[i];
					hr[i] = hr[j];
					hr[j] = t;
					t = wr[i];
					wr[i] = wr[j];
					wr[j] = t;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 1 << r; i++)
		{
			int sign = Integer.bitCount(i);
			if (sign % 2 == 0)
			{
				sign = 1;
			}
			else
			{
				sign = -1;
			}
			int res = 1;
			int curw = 1;
			int curh = 1;
			for (int j = 0; j < r; j++)
			{
				if ((i & (1 << j)) > 0)
				{
					res = (res * calcAns(hr[j] - curh, wr[j] - curw)) % p;
					curh = hr[j];
					curw = wr[j];
				}
			}
			res = (res * calcAns(h - curh, w - curw)) % p;
			res = (res * sign + p) % p;
			ans = (ans + res) % p;
		}
		return ans + "";
	}
	final static int p = 10007;
	int[] cs;

	int[] alphas;
	
	int[] revp;
	
	public int calcAns(int w, int h)
	{
		if (w < 0 || h < 0)
		{
			return 0;
		}
		if ((w + h) % 3 != 0)
		{
			return 0;
		}
		int a = (2 * w - h) / 3;
		int b = (2 * h - w) / 3;
		if (a < 0 || b < 0)
		{
			return 0;
		}
		return bin(a, b);
	}

	public int bin(int a, int b)
	{
		int d1 = alphas[a];
		int d2 = alphas[b];
		int d3 = alphas[a + b];
		if (d3 > d1 + d2)
		{
			return 0;
		}
		int v = (cs[a + b] * revp[cs[a]]) % p;
		return (v * revp[cs[b]]) % p;
	}
	public void init()
	{
		cs = new int[100000000];
		alphas = new int[100000000];
		cs[0] = 1;
		alphas[0] = 0;
		for (int i = 1; i < alphas.length; i++)
		{
			int j = i;
			alphas[i] = alphas[i - 1];
			while (j % p == 0)
			{
				j /= p;
				alphas[i]++;
			}
			cs[i] = (int) ((j * (long) cs[i - 1]) % p);
		}
		revp = new int[p];
		for (int i = 1; i < p; i++)
		{
			for (int j = 1; j < p; j++)
			{
				if ((i * j % p) == 1)
				{
					revp[i] = j;
					break;
				}
			}

		}
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
		new Thread(new D()).start();
	}
	static BufferedReader stdin;
	static BufferedWriter stdout;
	int test;
}
