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

	List<int>[] G;
	int N;
	int[] num;
	int[,] range;
	int root = 0;

	void prog()
	{
		cin = new Scanner();
		int[,] dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		int[,] dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		N = cin.nextInt();
		G = new List<int>[N];
		num = new int[N];
		range = new int[N, 2];

		for (int i = 0; i < N; i++)
		{
			G[i] = new List<int>();
			num[i] = -1;
		}
		for (int i = 0; i < N-1; i++)
		{
			int A = cin.nextInt() - 1;
			int B = cin.nextInt() - 1;
			G[A].Add(B);
			G[B].Add(A);
		}
		int K = cin.nextInt();
		for (int i = 0; i < K; i++)
		{
			int V = cin.nextInt() - 1;
			int P = cin.nextInt();
			num[V] = P;
			root = V;
		}
		if (!dfs(root, -1, num[root] % 2 == 0))
		{
			Console.WriteLine("No");
			return;
		}
		if (!set(root, -1, num[root] % 2 == 0))
		{
			Console.WriteLine("No");
			return;
		}
		Console.WriteLine("Yes");
		for (int i = 0; i < N; i++)
		{
			Console.WriteLine(num[i]);
		}
	}

	bool set(int pos, int parent, bool even)
	{
		if (pos != root && num[pos] == -1)
		{
			if (num[parent] + 1 >= range[pos, 0] && num[parent] + 1 <= range[pos, 1])
			{
				num[pos] = num[parent] + 1;
			}
			else if(num[parent] - 1 >= range[pos, 0] && num[parent] - 1 <= range[pos, 1])
			{
				num[pos] = num[parent] - 1;
			}
			else
			{
				return false;
			}
		}
		for (int i = 0; i < G[pos].Count; i++)
		{
			if (G[pos][i] == parent) continue;
			if (!set(G[pos][i], pos, !even)) return false;
		}
		return true;
	}

	bool dfs(int pos, int parent, bool even)
	{
		int min = -INF, max = INF;
		for (int i = 0; i < G[pos].Count; i++)
		{
			if (G[pos][i] == parent) continue;
			if (dfs(G[pos][i], pos, !even))
			{
				min = Math.Max(min, range[G[pos][i], 0] - 1);
				max = Math.Min(max, range[G[pos][i], 1] + 1);
			}
			else
			{
				return false;
			}
		}
		if (num[pos] != -1)
		{
			if (num[pos] < min || max < num[pos] || (num[pos] % 2 == 0) != even )
			{
				return false;
			}
			else
			{
				range[pos, 0] = num[pos];
				range[pos, 1] = num[pos];
				return true;
			}
		}
		else
		{
			range[pos, 0] = min;
			range[pos, 1] = max;
			return true;
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