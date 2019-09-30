using System;
using System.Collections.Generic;
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
	
	public string Solve()
	{
		string[] ss = Console.ReadLine().Split(' ');
		int n = int.Parse(ss[0]);
		List<int>[] g = new List<int>[n + 1];
		for (int i = 0; i <= n; ++i)
			g[i] = new List<int>();
		
		ss = Console.ReadLine().Split(' ');
		foreach (string s in ss)
		{
			ss = s.Split(',');
			int a = int.Parse(ss[0]);
			int b = int.Parse(ss[1]);
			g[a].Add(b);
			g[b].Add(a);
		}
		
		int[] l = new int[n];
		for (int i = 0; i < n; ++i)
			l[i] = -1;
		l[0] = 0;
		
		List<int> src = new List<int>();
		src.Add(0);
		
		while(src.Count > 0)
		{
			List<int> dst = new List<int>();
			foreach (int q in src)
			{
				foreach (int qq in g[q])
					if (l[qq] == -1)
				{
					l[qq] = l[q] + 1;
					dst.Add(qq);
				}
			}
			
			src = dst;
		}
		
		if (l[1] == -1)
			throw new Exception();
		
		Dictionary<int, int>[] sc = new Dictionary<int, int>[n];
		for (int i = 0; i < n; ++i)
			sc[i] = new Dictionary<int, int>();
		
		sc[0][n] = g[0].Count;
		
		for (int ll = 1; ll < l[1]; ++ll)
			for (int i = 0; i < n; ++i)
				if (l[i] == ll)
			{
				foreach (int j in g[i])
					if (l[j] == ll - 1)
				{
					int best = 0;
					
					foreach(KeyValuePair<int, int> kvp in sc[j])
					{
						int k = kvp.Key;
						int score = kvp.Value - 1;
						
						HashSet<int> mam = new HashSet<int>();
						mam.Add(j);
						foreach (int q in g[k])
							mam.Add(q);
						foreach (int q in g[j])
							mam.Add(q);
						foreach (int q in g[i])
							if (!mam.Contains(q))
								++score;
						
						best = Math.Max(best, score);
					}
					
					sc[i][j] = best;
				}
			}
		
		int tbest = 0;
		foreach (int q in g[1])
			foreach (KeyValuePair<int, int> kvp in sc[q])
				tbest = Math.Max(tbest, kvp.Value);
		
		return string.Format("{0} {1}", l[1] - 1, tbest);
	}
}