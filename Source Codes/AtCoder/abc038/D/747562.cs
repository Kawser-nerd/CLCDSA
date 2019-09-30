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

		int N = cin.nextInt();

		Pair[] box = new Pair[N];

		for (int i = 0; i < N; i++)
		{
			box[i] = new Pair(cin.nextInt(), cin.nextInt());
		}

		Array.Sort<Pair>(box, (a, b) => (a.Key > b.Key ? 1 : (a.Key < b.Key ? -1 : (a.Value < b.Value ? 1 : (a.Value > b.Value ? -1 : 0)))));
		SegTreeMax segtree = new SegTreeMax(100001);
		int ans = 0;

		for (int i = 0; i < N; i++)
		{
			int h = box[i].Value;
			int now = segtree.getMax(0, h) + 1;
			ans = Math.Max(ans, now);
			segtree.add(h, now);
		}
		Console.WriteLine(ans);
	}
}
class SegTreeMax
{
	int n;  // ??????
	int[] d;

	public int getMax(int a, int b, int i = 1, int l = 0, int r = -1)
	{
		if (r == -1) r = n;
		if (a <= l && r <= b) return d[i];
		int ret = 0;
		int c = (l + r) >> 1;
		if (a < c) ret = Math.Max(ret, getMax(a, b, i << 1, l, c));
		if (c < b) ret = Math.Max(ret, getMax(a, b, (i << 1) | 1, c, r));
		return ret;
	}

	public void add(int i, int x)
	{
		i += n;
		while (i > 0)
		{
			d[i] = Math.Max(d[i], x);
			i >>= 1;
		}
	}

	public int this[int i]
	{
		get
		{
			return d[i + n];
		}
	}

	public SegTreeMax(int size)
	{
		n = 1;
		while (n < size) n <<= 1;
		d = new int[n << 1];
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