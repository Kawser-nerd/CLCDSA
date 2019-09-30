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

	int N;
	int[] A, B;

	void prog()
	{
		cin = new Scanner();
		dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		N = cin.nextInt();
		A = new int[N];
		B = new int[N+1];

		for (int i = 0; i < N; i++)
		{
			A[i] = cin.nextInt();
			B[A[i]] = i;
		}
		UnionFind uf = new UnionFind(N + 1);
		long ans = 0;
		for (int i = N; i > 0; i--)
		{
			int idx = B[i];
			ans += A[idx];
			if (idx - 1 >= 0 && A[idx - 1] > A[idx])
			{
				ans += uf.unite(idx, idx - 1) * A[idx];
			}
			if (idx + 1 < N && A[idx + 1] > A[idx])
			{
				ans += uf.unite(idx, idx + 1) * A[idx];
			}
		}
		Console.WriteLine(ans);
	}

	class UnionFind
	{
		int N;
		int[] parent;
		int[] rank;
		int[] size;

		public UnionFind(int N)
		{
			this.N = N;
			parent = new int[N];
			rank = new int[N];
			size = new int[N];
			for (int i = 0; i < N; i++)
			{
				parent[i] = i;
				size[i] = 1;
			}
		}

		public int find(int x)
		{
			if (parent[x] == x)
			{
				return x;
			}
			else
			{
				return parent[x] = find(parent[x]);
			}
		}

		public long unite(int x, int y)
		{
			x = find(x);
			y = find(y);
			long s = (long)size[x] * size[y];
			if (rank[x] < rank[y])
			{
				parent[x] = y;
				size[y] += size[x];
			}
			else
			{
				parent[y] = x;
				size[x] += size[y];
				if (rank[x] == rank[y]) rank[x]++;
			}
			return s;
		}

		public bool same(int x, int y)
		{
			return find(x) == find(y);
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