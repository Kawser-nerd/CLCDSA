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
	const double EPS = 1e-7;
	const double PI = 3.1415926536;

	void prog()
	{
		cin = new Scanner();
		int[,] dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		int[,] dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		int N = cin.nextInt();
		int x = cin.nextInt();

		if (N == 1)
		{
			Console.WriteLine("Yes");
			Console.WriteLine(1);
			return;
		}

		if (x == 1 || x == 2 * N - 1)
		{
			Console.WriteLine("No");
			return;
		}
		Console.WriteLine("Yes");
		int[] ans = new int[2 * N - 1];
		ans[N - 2] = 1;
		ans[N - 1] = x;
		ans[N] = 2 * N - 1;
		if (N >= 3)
		{
			if (x != 2 * N - 2)
			{
				ans[N - 3] = 2 * N - 2;
			}
			if (x != 2)
			{
				ans[N + 1] = 2;
			}
		}
		int num = x != 2 ? 3 : 2;
		for (int i = 0; i < 2 * N - 1; i++)
		{
			if (ans[i] != 0) continue;
			if (num == x) num++;
			ans[i] = num;
			num++;
		}
		//*
		for (int i = 0; i < 2 * N - 1; i++)
		{
			Console.WriteLine(ans[i].ToString());
		}
		//*/ Console.WriteLine("end");
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