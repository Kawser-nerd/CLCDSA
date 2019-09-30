using System;
using System.Linq;

public class MainClass
{
	public static void Main (string[] args)
	{
		MainClass task = new MainClass();
		
		int n = int.Parse(Console.ReadLine());
		for(int i = 1; i <= n; ++i)
			Console.WriteLine("Case #{0}: {1}", i, task.Solve());
	}
	
	int[,] q, ac;
	
	public string Solve()
	{
		string[] ss = Console.ReadLine().Split(' ');
		int r = int.Parse(ss[0]);
		int c = int.Parse(ss[1]);
		
		q = new int[r + 1, c + 1];
		for (int i = 0; i < r; ++i)
		{
			string s = Console.ReadLine();
			for (int j = 0; j < c; ++j)
				q[i + 1, j + 1] = (int)(s[j] - '0');
		}
		
		ac = new int[r + 1, c + 1];
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
				ac[i, j] = ac[i - 1, j] + ac[i, j - 1] - ac[i - 1, j - 1] + q[i, j];
		
		for (int res = Math.Min(r, c); res >= 3; --res)
			if (possible(r, c, res))
				return res.ToString();
		
		return "IMPOSSIBLE";
	}
	
	bool possible(int r, int c, int sz)
	{
		bool[,] ok = new bool[r + 1, c + 1];
		
		for (int i = sz; i <= r; ++i)
		{
			int bal = 0;
			for (int j = 1; j < sz; ++j)
				bal += ac[i, j] - ac[i - sz, j];
			
			for (int j = sz; j <= c; ++j)
			{
				int sq = ac[i, j] + ac[i - sz, j - sz] - ac[i, j - sz] - ac[i - sz, j];
				
				int cbal = 2 * bal - (sz - 1) * sq;
				cbal += (sz - 1) * (q[i, j] + q[i - sz + 1, j] - q[i, j - sz + 1] - q[i - sz + 1, j - sz + 1]);
				ok[i, j] = cbal == 0;
				
				bal += sq;
				bal -= sz * (ac[i, j - sz + 1] + ac[i - sz, j - sz] - ac[i - sz, j - sz + 1] - ac[i, j - sz]);
			}
		}
		
		for (int i = sz; i <= c; ++i)
		{
			int bal = 0;
			for (int j = 1; j < sz; ++j)
				bal += ac[j, i] - ac[j, i - sz];
			
			for (int j = sz; j <= r; ++j)
			{
				int sq = ac[j, i] + ac[j - sz, i - sz] - ac[j - sz, i] - ac[j, i - sz];
				
				int cbal = 2 * bal - (sz - 1) * sq;
				cbal += (sz - 1) * (q[j, i] + q[j, i - sz + 1] - q[j - sz + 1, i] - q[j - sz + 1, i - sz + 1]);
//				Console.WriteLine("{0} {1} {2}: {3} {4} {5}", j, i, sz, bal, sq, cbal);
//				if (cbal == 0)
//					Console.WriteLine ("{0} {1} {2}", j, i, sz);
				if (cbal == 0 && ok[j, i])
					return true;
				
				bal += sq;
				bal -= sz * (ac[j - sz + 1, i] + ac[j - sz, i - sz] - ac[j - sz + 1, i - sz] - ac[j - sz, i]);
			}
		}
		
		return false;
	}
}