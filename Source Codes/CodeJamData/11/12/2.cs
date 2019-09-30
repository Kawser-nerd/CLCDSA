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
	
	int getsig(string orig, char c)
	{
		int res = 0;
		
		foreach(char _c in orig)
		{
			res <<= 1;
			res += (_c == c) ? 1 : 0;
		}
		
		return res;
	}
	
	public string Solve()
	{
		string[] s = Console.ReadLine().Split(' ');
		int n = int.Parse(s[0]);
		int m = int.Parse(s[1]);
		
		string[] w = new string[n];
		for (int i = 0; i < n; ++i)
			w[i] = Console.ReadLine();
		
		List<int>[] wl = new List<int>[11];
		for (int i = 1; i <= 10; ++i)
			wl[i] = new List<int>();
		for (int i = 0; i < n; ++i)
			wl[w[i].Length].Add(i);
		
		int[,] ws = new int[n, 26];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 26; ++j)
				ws[i, j] = getsig(w[i], (char)((int)'a' + j));
		
		string[] res = new string[m];
		for (int i = 0; i < m; ++i)
			res[i] = w[solve(ws, wl, Console.ReadLine())];
		
		return string.Join(" ", res);
	}
	
	int bestw;
	int beste;
	
	int solve(int[,] ws, List<int>[] wl, string d)
	{
		bestw = -1;
		beste = -1;
		
		for (int i = 1; i <= 10; ++i)
			if (wl[i].Count > 0)
				solve(ws, wl[i], d, 0, 0);
		
		return bestw;
	}
	
	void solve(int[,] ws, List<int> wl, string d, int cnt, int pts)
	{
		if (wl.Count == 1)
		{
			if (pts > beste || (pts == beste && wl[0] < bestw))
			{
				bestw = wl[0];
				beste = pts;
			}
			
			return;
		}
		
		if (cnt == d.Length)
			throw new Exception();
		
		List<int>[] grp = new List<int>[1024];
		int l = (int)(d[cnt] - 'a');
		
		foreach(int w in wl)
		{
			int idx = ws[w, l];
			if(grp[idx] == null)
				grp[idx] = new List<int>();
			grp[idx].Add(w);
		}
		
	    for (int i = 0; i < 1024; ++i)
			if (grp[i] != null)
				solve(ws, grp[i], d, cnt + 1, pts + ((i == 0 && grp[0].Count != wl.Count) ? 1 : 0));
	}
}