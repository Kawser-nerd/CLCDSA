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
		for (int i = 0; i < N; i++)
		{
			x[i] = cin.nextInt();
		}
		int L = cin.nextInt();
		int Q = cin.nextInt();
		int[] a = new int[Q];
		int[] b = new int[Q];
		for (int i = 0; i < Q; i++)
		{
			a[i] = cin.nextInt() - 1;
			b[i] = cin.nextInt() - 1;
			if (a[i] > b[i])
			{
				int tmp = a[i];
				a[i] = b[i];
				b[i] = tmp;
			}
		}

		int depth = 17;
		int[,] r = new int[depth, N];
		for (int i = 0; i < N - 1; i++)
		{
			if (x[N - 1] - x[i] <= L)
			{
				for (int j = i; j < N; j++)
				{
					r[0, j] = N - 1;
				}
				break;
			}
			int ok = i + 1, ng = N - 1;
			while (ng - ok > 1)
			{
				int mid = (ok + ng) / 2;
				if (x[mid] - x[i] > L)
				{
					ng = mid;
				}
				else
				{
					ok = mid;
				}
			}
			r[0, i] = ok;
			/*
			for (int j = i + 2; j < N; j++)
			{
				if (x[j] - x[i] > L)
				{
					r[0, i] = j - 1;
					break;
				}
			}
			*/
		}
		r[0, N - 2] = N - 1;
		r[0, N - 1] = N - 1;
		for (int i = 1; i < depth; i++)
		{
			for (int j = 0; j < N; j++)
			{
				r[i, j] = r[i - 1, r[i - 1, j]];
			}
		}
		for (int i = 0; i < Q; i++)
		{
			int ok = (1 << 17) - 1, ng = 0;
			while (ok - ng > 1)
			{
				int now = a[i];
				int nowdepth = 0;
				int mid = (ok + ng) / 2;
				while (mid > 0)
				{
					if ((mid & 1) == 1)
					{
						now = r[nowdepth, now];
					}
					nowdepth++;
					mid >>= 1;
				}
				if (now >= b[i])
				{
					ok = (ok + ng) / 2;
				}
				else
				{
					ng = (ok + ng) / 2;
				}
			}
			Console.WriteLine(ok);
		}
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