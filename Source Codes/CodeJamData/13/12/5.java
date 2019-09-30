import java.io.*;
import java.util.*;

public class Solution implements Runnable
{
	BufferedReader in;
	StringTokenizer tokenizer;
	PrintWriter out;
	
	private void solve() throws Exception
	{
		int tests = nextInt();
		for (int test = 0; test < tests; test++) {
			System.err.println(test + 1);
			out.printf("Case #%d: %d\n", test + 1, solveTest());
		}
	}
	
	long solveTest() throws Exception
	{
		long E = nextLong();
		long R = nextLong();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		long e = E;
		long res = 0;
		for (int i = 0; i < n; i++) {
			int j;
			for (j = i + 1; j < n; j++) {
				if (a[j] >= a[i]) break;
				// || (j - i) * R > (E - e)) break;
			}
			if (j == n) {
				res += a[i] * e;
				e = 0;
			} else {
				long e2 = e + (j - i) * R;
				long use = Math.min(e, Math.max(0, e2 - E));
				e -= use;
				res += a[i] * use;
			}
			e += R;
			if (e > E) {
				e = E;
//				throw new RuntimeException();
			}
		}
		return res;
	}

	private int nextInt() throws Exception
	{
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception
	{
		return Long.parseLong(next());
	}

	private String next() throws Exception
	{
		if (tokenizer == null || !tokenizer.hasMoreTokens())
		{
			String s = "";
			while (s.equals(""))
			{
				s = in.readLine();
			}
			tokenizer = new StringTokenizer(s);
		}
		return tokenizer.nextToken();
	}

	public void run()
	{
		try
		{
			solve();
		}
		catch (Exception ex)
		{
			throw new RuntimeException(ex);
		}
		finally
		{
			out.close();
		}
	}
	
	public Solution() throws IOException
	{
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
	}

	public static void main(String[] args) throws IOException
	{
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
}
