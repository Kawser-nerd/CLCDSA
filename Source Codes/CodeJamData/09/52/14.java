import java.util.*;
import java.io.*;
import java.math.*;

public class B
{
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
	private String fileName = "B-small-attempt1";
	final int MOD = 10009;

	private void solution() throws IOException
	{
		// long time = System.currentTimeMillis();
		in = new Scanner(new FileReader(fileName + ".in"));
		out = new PrintWriter(fileName + ".out");
		int test = in.nextInt();
		for (int cas = 1; cas <= test; ++cas)
		{
			out.printf("Case #%d:", cas);
			solve();
			out.println();
			System.out.println(cas + " done");
		}
		// System.out.println((System.currentTimeMillis() - time) * 10);
		out.flush();
	}
	String[] lex;
	String[] words;
	int[] res;
	int k;
	int[] c = new int[26];
	int have;
	int last = 0;
	ArrayList<String> ar = new ArrayList<String>();

	private void solve() throws IOException
	{
		String pal = in.next();
		lex = pal.split("[+]");
		this.k = in.nextInt();
		res = new int[k + 1];
		int n = in.nextInt();
		words = new String[n];
		for (int i = 0; i < words.length; ++i)
			words[i] = in.next();
		count();
		for (int i = 1; i <= k; ++i)
			out.print(" " + res[i]);
	}

	private void count()
	{
		check();
		int tmpLast = last;
		if (have < k)
		{
			for (int i = last; i < words.length; ++i)
			{
				last = i;
				for (int j = 0; j < words[i].length(); ++j)
					++c[words[i].charAt(j) - 'a'];
				++have;
				ar.add(words[i]);
				count();
				ar.remove(ar.size() - 1);
				--have;
				for (int j = 0; j < words[i].length(); ++j)
					--c[words[i].charAt(j) - 'a'];
			}
		}
		last = tmpLast;
	}

	private void check()
	{
		int r = 0;
		for (String l : lex)
		{
			int cur = 1;
			for (int j = 0; j < l.length(); ++j)
				cur = (cur * c[l.charAt(j) - 'a']) % MOD;
			r = (r + cur) % MOD;
		}
		res[have] = (int) ((res[have] + r * ways()) % MOD);
	}

	private long ways()
	{
		long res = 1;
		int n = ar.size();
		for (int i = 0; i < ar.size(); ++i)
		{
			int j = i;
			while (j < ar.size() && ar.get(i).equals(ar.get(j)))
				++j;
			res *= cnk(n, j - i);
			n -= j - i;
			i = j - 1;
		}
		return res;
	}

	private long fact(int n)
	{
		long res = 1;
		for (int i = 1; i <= n; ++i)
			res = (res * i) % MOD;
		return res;
	}

	private long cnk(int n, int k)
	{
		long res = 1;
		if (k > n - k)
			k = n - k;
		for (int i = 0; i < k; ++i)
			res = res * (n - i) / (i + 1);
		return res;
	}

	private class Scanner
	{
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public Scanner(Reader in)
		{
			reader = new BufferedReader(in);
			tokenizer = new StringTokenizer("");
		}

		public boolean hasNext() throws IOException
		{
			while (!tokenizer.hasMoreTokens())
			{
				String tmp = reader.readLine();
				if (tmp == null)
					return false;
				tokenizer = new StringTokenizer(tmp);
			}
			return true;
		}

		public String next() throws IOException
		{
			hasNext();
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException
		{
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException
		{
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException
		{
			return Double.parseDouble(next());
		}

		public String nextLine() throws IOException
		{
			tokenizer = new StringTokenizer("");
			return reader.readLine();
		}
	}

	public static void main(String[] args) throws IOException
	{
		new B().solution();
	}
}
