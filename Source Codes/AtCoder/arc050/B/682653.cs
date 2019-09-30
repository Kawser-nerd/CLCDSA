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
	
	bool[] visited;
	List<Pair>[] dp;
	
	
	void prog()
	{
		cin = new Scanner();

		long R = cin.nextLong();
		long B = cin.nextLong();
		int x = cin.nextInt();
		int y = cin.nextInt();
		long ok = 0, ng = Math.Max(R, B);
		while (ng - ok != 1)
		{
			long mid = (ok + ng) / 2;
			if (check(R, B, x, y, mid)) ok = mid;
			else ng = mid;
		}
		Console.WriteLine(ok);
	}

	bool check(long R, long B, int x, int y, long n)
	{
		R -= n;
		B -= n;
		x--;
		y--;
		if (R < 0 || B < 0) return false;
		long num = R / x + B / y;
		if (num < n) return false;
		return true;
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