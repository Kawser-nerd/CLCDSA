using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;

using Pair = System.Collections.Generic.KeyValuePair<int, int>;

class Program
{
	public Program() { }

	static void Main(string[] args)
	{
		new Program().prog();
	}

	Scanner cin;

	const int MOD = 1000000007;
	const int INF = int.MaxValue - 10;
	const long INFL = long.MaxValue - 10;
	const double EPS = 1e-8;
	const double PI = 3.1415926536;
	int[,] dir8;
	int[,] dir4;



	void prog()
	{
		cin = new Scanner();
		dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		int N = cin.nextInt();
		int K = cin.nextInt();
		long[] a = new long[N];
		long[] b = new long[N];
		for (int i = 0; i < N; i++)
		{
			if (i == 0)
			{
				a[0] = cin.nextInt();
				b[0] = Math.Max(0, a[0]);
			}
			else
			{
				int num = cin.nextInt();
				a[i] = a[i - 1] + num;
				b[i] = b[i - 1] + Math.Max(0, num);
			}
		}
		long ans = 0;
		for (int i = 0; i <= N-K; i++)
		{
			long ans1 = Math.Max(0, a[i + K - 1] - (i == 0 ? 0 : a[i - 1]));
			if (i != 0) ans1 += b[i - 1];
			ans1 += b[N - 1] - b[i + K - 1];
			ans = Math.Max(ans, ans1);
		}
		Console.WriteLine(ans);
	}
}

class Scanner
{
	string[] s;
	int i;

	char[] cs = new char[] { ' ' };

	public Scanner()
	{
		s = new string[0];
		i = 0;
	}

	public string next()
	{
		if (i < s.Length) return s[i++];
		string st = Console.ReadLine();
		while (st == "") st = Console.ReadLine();
		s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
		i = 0;
		return next();
	}

	public int nextInt()
	{
		return int.Parse(next());
	}

	public long nextLong()
	{
		return long.Parse(next());
	}

	public double nextDouble()
	{
		return double.Parse(next());
	}
}