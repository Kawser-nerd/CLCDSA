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
	
	void prog()
	{
		cin = new Scanner();
		int[,] dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		int[,] dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
 
		int xs = cin.nextInt();
		int ys = cin.nextInt();
		int xt = cin.nextInt();
		int yt = cin.nextInt();
 
		int N = cin.nextInt();
		double[,] dist = new double[10 * N + 2, 10 * N + 2];
		long[] x = new long[N];
		long[] y = new long[N];
		long[] r = new long[N];
		for (int i = 0; i < N; i++)
		{
			x[i] = cin.nextInt();
			y[i] = cin.nextInt();
			r[i] = cin.nextInt();
		}
		dist[0, N + 1] = Math.Max(0, Math.Sqrt((long)(xs - xt) * (xs - xt) + (long)(ys - yt) * (ys - yt)));
		dist[N + 1, 0] = Math.Max(0, Math.Sqrt((long)(xs - xt) * (xs - xt) + (long)(ys - yt) * (ys - yt)));
		for (int i = 0; i < N; i++)
		{
			dist[0, i + 1] = Math.Max(0, Math.Sqrt((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys)) - r[i]);
			dist[i + 1, 0] = Math.Max(0, Math.Sqrt((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys)) - r[i]);
			for (int j = i + 1; j < N; j++)
			{
				dist[i + 1, j + 1] = Math.Max(0, Math.Sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]);
				dist[j + 1, i + 1] = Math.Max(0, Math.Sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]);
			}
			dist[i + 1, N + 1] = Math.Max(0, Math.Sqrt((x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt)) - r[i]);
			dist[N + 1, i + 1] = Math.Max(0, Math.Sqrt((x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt)) - r[i]);
		}
		/*
		Console.WriteLine();
		for (int i = 0; i < N+2; i++)
		{
			for (int j = 0; j < N+2; j++)
			{
				Console.Write("{0} ",dist[i,j]);
			}
			Console.WriteLine();
		}
		Console.WriteLine();
		//*/
		Console.WriteLine("{0:0.00000000000000}", Dijkstra(dist, 0, N + 1, N + 2));
	}
 
	// ???????O(n^2)?start?goal???????
	double Dijkstra(double[,] adjacent, int start, int goal, int N)
	{
		bool[] visited = new bool[N];
		double[] dist = new double[N];
		int[] prev = new int[N];
 
		for (int i = 0; i < N; i++)
		{
			dist[i] = INFL;
			prev[i] = -1;
		}
		dist[start] = 0;
		prev[start] = start;
		double min;
		int pos = start;
		while (true)
		{
			min = INFL;
			int next = -1;
			visited[pos] = true;
			for (int i = 0; i < N; i++)
			{
				if (visited[i]) continue;
				if (pos != i)
				{
					double d = dist[pos] + adjacent[pos, i];
					if (d < dist[i])
					{
						dist[i] = d;
						prev[i] = pos;
					}
				}
				if (dist[i] < min)
				{
					min = dist[i];
					next = i;
				}
			}
			if (next == goal) break;
			pos = next;
		}
		return dist[goal];
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