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
		int[] x = new int[N];
		int[] y = new int[N];
		int[] c = new int[N];
		int xmax = 0, ymax = 0;
		int xmin = int.MaxValue, ymin = int.MaxValue;
		for (int i = 0; i < N; i++)
		{
			x[i] = cin.nextInt();
			y[i] = cin.nextInt();
			c[i] = cin.nextInt();
			xmax = Math.Max(xmax, x[i]);
			ymax = Math.Max(ymax, y[i]);
			xmin = Math.Min(xmin, x[i]);
			ymin = Math.Min(ymin, y[i]);
		}
		double a = 0, b = 1000 * Math.Max(xmax, ymax);
		while (b - a > 1e-6)
		{
			double mid = (a + b) / 2;
			double rmin = xmax, lmax = xmin, umin = ymax, dmax = ymin;
			for (int i = 0; i < N; i++)
			{
				rmin = Math.Min(rmin, x[i] + mid / c[i]);
				lmax = Math.Max(lmax, x[i] - mid / c[i]);
				umin = Math.Min(umin, y[i] + mid / c[i]);
				dmax = Math.Max(dmax, y[i] - mid / c[i]);
			}
			if (lmax <= rmin && dmax <= umin)
			{
				b = mid;
			}
			else
			{
				a = mid;
			}
		}
		Console.WriteLine((a + b) / 2);
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