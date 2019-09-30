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

		long n = cin.nextLong();
		long s = cin.nextLong();
		if (s > n)
		{
			Console.WriteLine(-1);
			return;
		}
		List<int> list = new List<int>();
		for (int i = 2; i <= Math.Sqrt(n) + 0.5; i++)
		{
			long f = 0;
			long m = n;
			while (m > 0)
			{
				f += m % i;
				m /= i;
			}
			if (f == s)
			{
				Console.WriteLine(i);
				return;
			}
		}
		for (int i = 1; i <= Math.Sqrt(n - s) + 0.5; i++)
		{
			if ((n - s) % i == 0) list.Add(i);
		}
		for (int i = 1; i < list.Count; i++)
		{
			if (list[i] < Math.Sqrt(n)) continue;
			long b = list[i] + 1;
			long f = 0;
			long m = n;
			while (m > 0)
			{
				f += m % b;
				m /= b;
			}
			if (f == s)
			{
				Console.WriteLine(b);
				return;
			}
		}
		for (int i = list.Count - 1; i >= 0; i--)
		{
			long b = (n - s) / list[i] + 1;
			long f = 0;
			long m = n;
			while (m > 0)
			{
				f += m % b;
				m /= b;
			}
			if (f == s)
			{
				Console.WriteLine(b);
				return;
			}
		}
		if (n == s) Console.WriteLine(n + 1);
		else Console.WriteLine(-1);
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