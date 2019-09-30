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
	const int INF = int.MaxValue;
	const long INFL = long.MaxValue;
	const double EPS = 1e-7;
	const double PI = 3.1415926536;

	int[] p = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

	int MAX = 1000000000;

	void prog()
	{
		cin = new Scanner();
		int[,] dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		int[,] dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		int N = cin.nextInt();
		int T = cin.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++)
		{
			A[i] = cin.nextInt();
		}
		int[] max = new int[N];
		max[N - 1] = A[N - 1];
		int[] diff = new int[N];
		int max_diff=0;
		for (int i = N-2; i >= 0; i--)
		{
			max[i] = Math.Max(max[i+1], A[i]);
			diff[i] = max[i] - A[i];
			max_diff = Math.Max(max_diff, diff[i]);
		}
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			if (diff[i] == max_diff) ans++;
			//Console.WriteLine(max[i]);
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