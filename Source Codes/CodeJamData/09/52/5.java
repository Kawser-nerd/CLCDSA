import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Locale;

// 1.6
public class B2
{
	static final int THREADS = 1;

	static final String NAME = "b-large";

	StringBuilder out;

	String[] poly;

	int K;

	int N;

	int[][] words;

	public void readData() throws Exception
	{
		String p = readWord();
		poly = p.split("\\+");
		K = Integer.parseInt(readWord());
		N = Integer.parseInt(readWord());
		words = new int[N][26];
		for (int i = 0; i < N; i++)
		{
			String s = readWord();
			for (int j = 0; j < s.length(); j++)
			{
				words[i][s.charAt(j) - 'a']++;
			}
		}
	}

	int d;

	int[] ans;

	static class Stat
	{
		int[] freq;

		public Stat(int[] freq)
		{
			this.freq = freq.clone();
		}

		@Override
		public int hashCode()
		{
			return Arrays.hashCode(freq);
		}

		@Override
		public boolean equals(Object obj)
		{
			if (this == obj)
				return true;
			// if (obj == null)
			// return false;
			// if (getClass() != obj.getClass())
			// return false;
			Stat other = (Stat) obj;

			if (!Arrays.equals(freq, other.freq))
				return false;
			return true;
		}

	}

	final static int MOD = 10009;

	Stat tmpStat = new Stat(new int[0]);
	public void add(HashMap<Stat, Integer> next, int[] tmp, int value)
	{
		// Stat s = new Stat(tmp);
		tmpStat.freq = tmp;
		Integer i = next.get(tmpStat);
		if (i == null)
		{
			next.put(new Stat(tmp), value);
		}
		else
		{
			next.put(tmpStat, (value + i) % MOD);
		}
	}

	int[] pp;

	public int rec(int[] data, int cur, int nextInd, int coeff)
	{
		if (cur == data.length)
		{
			int res = coeff;
			for (int i = nextInd; i < d; i++)
			{
				res = (res * N) % MOD;
			}
			for (int i = 0; i < nextInd; i++)
			{
				int sum = 0;
				for (int j = 0; j < N; j++)
				{
					int mult = 1;
					for (int k = 0; k < data.length; k++)
					{
						if (data[k] == i)
						{
							mult = (mult * words[j][pp[k]]) % MOD;
						}
					}
					sum = (sum + mult) % MOD;
				}
				res = (res * sum) % MOD;
			}
			return res;
		}
		int res = 0;
		for (int i = 0; i < nextInd; i++)
		{
			data[cur] = i;
			res += rec(data, cur + 1, nextInd, coeff);
		}
		if (nextInd < d)
		{
			data[cur] = nextInd;
			res += rec(data, cur + 1, nextInd + 1, (coeff * (d - nextInd)) % MOD);
		}
		return res % MOD;
	}
	public void solve()
	{
		ans = new int[K];
		for (int npoly = 0; npoly < poly.length; npoly++)
		{
			char[] p = poly[npoly].toCharArray();
			pp = new int[p.length];
			for (int i = 0; i < p.length; i++)
			{
				pp[i] = p[i] - 'a';
			}
			for (d = 1; d <= K; d++)
			{
				int[] data=new int[pp.length];
				ans[d - 1] = (ans[d - 1] + rec(data, 0, 0, 1)) % MOD;
			}
		}
		for (int i = 0; i < K; i++)
		{
			out.append(ans[i] + " ");
		}
		out.append("\n");
	}

	static String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
		while (true)
		{
			c = Common.stdin.read();
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
			c = Common.stdin.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	static String readLine() throws Exception
	{
		return Common.stdin.readLine();
	}

	static class Common
	{
		static BufferedReader stdin;

		static BufferedWriter stdout;

		static int tests;

		static int test;

		static String[] answers;

		public static void startThreads()
		{
			try
			{
				stdin = new BufferedReader(new FileReader(NAME + ".in"));
				stdout = new BufferedWriter(new FileWriter(NAME + ".out"));
				tests = Integer.parseInt(readLine().trim());
				answers = new String[tests];
				test = 0;
				Thread[] threads = new Thread[THREADS];
				for (int i = 0; i < threads.length; i++)
				{
					final B2 inst = new B2();
					threads[i] = new Thread(new Runnable()
					{
						public void run()
						{
							while (true)
							{
								inst.out = new StringBuilder();
								int ltest = 0;
								synchronized (stdin)
								{
									ltest = test;
									test++;
									if (ltest >= tests)
									{
										return;
									}
									try
									{
										inst.readData();
									}
									catch (Throwable e)
									{
										e.printStackTrace();
									}
								}
								long t = System.currentTimeMillis();
								try
								{
									inst.solve();
								}
								catch (Throwable e)
								{
									e.printStackTrace();
								}
								System.err.println(ltest + " " + (System.currentTimeMillis() - t));
								synchronized (answers)
								{
									answers[ltest] = inst.out.toString();
								}
							}
						}
					});
					threads[i].start();
				}
				for (int i = 0; i < threads.length; i++)
				{
					threads[i].join();
				}
				for (int test = 1; test <= tests; test++)
				{
					stdout.write("Case #" + test + ": " + answers[test - 1]);
				}
				stdout.close();
				stdin.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args)
	{
		try
		{
			Locale.setDefault(Locale.US);
			Common.startThreads();
		}
		catch (Throwable e)
		{
			e.printStackTrace();
		}
	}
}
