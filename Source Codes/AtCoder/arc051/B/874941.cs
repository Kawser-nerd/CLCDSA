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

		int K = cin.nextInt();
		int[] f = new int[K + 1];
		f[0] = 1;
		f[1] = 2;
		for (int i = 2; i < K+1; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		Console.WriteLine("{0} {1}", f[K], f[K-1]);
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