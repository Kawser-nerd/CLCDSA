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

		long I = cin.nextInt();
		long O = cin.nextInt();
		int T = cin.nextInt();
		long J = cin.nextInt();
		long L = cin.nextInt();
		long ans1 = O;
		long ans2 = O;
		ans1 += (I / 2) * 2 + (J / 2) * 2 + (L / 2) * 2;
		if (I >= 1 && J >= 1 && L >= 1)
		{
			I--;
			J--;
			L--;
			ans2 += 3 + (I / 2) * 2 + (J / 2) * 2 + (L / 2) * 2;
		}
		Console.WriteLine(Math.Max(ans1, ans2));
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