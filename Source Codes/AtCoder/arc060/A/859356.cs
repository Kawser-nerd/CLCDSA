using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

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
	const int INF = int.MaxValue;
	const double EPS = 1e-7;
	const double PI = 3.1415926536;

	void prog()
	{
		cin = new Scanner();
		int[,] dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		int[,] dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		int N = cin.nextInt();
		int A = cin.nextInt();
		int[] x = new int[N];
		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			x[i] = cin.nextInt();
			sum += x[i];
		}

		long[,,] dp = new long[N, N + 1, sum + 1];

		for (int i = 0; i < N; i++)
		{
			dp[i, 0, 0] = 1;
		}
		dp[0, 1, x[0]] = 1;
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j <= N; j++)
			{
				for (int k = 0; k <= sum; k++)
				{
					dp[i, j, k] = dp[i - 1, j, k];
					if (k - x[i] >= 0 && j > 0)
					{
						dp[i, j, k] += dp[i - 1, j - 1, k - x[i]];
					}
				}
			}
		}

		long ans = 0;

		for (int i = 1; i <= N; i++)
		{
			if (i * A > sum) continue;
			ans += dp[N - 1, i, i * A];
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