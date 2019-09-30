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
		int r = int.Parse(ss[0]);
		int c = int.Parse(ss[1]);
		
		string[] s = new string[r];
		for (int i = 0; i < r; ++i)
			s[i] = Console.ReadLine();
		
		int n = r * c;
		List<int>[] a = new List<int>[n];
		List<int>[] b = new List<int>[n];
		for (int i = 0; i < n; ++i)
		{
			a[i] = new List<int>();
			b[i] = new List<int>();
		}
		
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
		{
			int aa = i * c + j;
			int bb1, bb2;
			
			if (s[i][j] == '-')
			{
				bb1 = i * c + ((j + 1) % c);
				bb2 = i * c + ((j + c - 1) % c);
			}
			else if (s[i][j] == '|')
			{
				bb1 = ((i + 1) % r) * c + j;
				bb2 = ((i + r - 1) % r) * c + j;
			}
			else if (s[i][j] == '\\')
			{
				bb1 = ((i + 1) % r) * c + ((j + 1) % c);
				bb2 = ((i + r - 1) % r) * c + ((j + c - 1) % c);
			}
			else
			{
				bb1 = ((i + 1) % r) * c + ((j + c - 1) % c);
				bb2 = ((i + r - 1) % r) * c + ((j + 1) % c);
			}
			
			a[aa].Add(bb1);
			a[aa].Add(bb2);
			b[bb1].Add(aa);
			b[bb2].Add(aa);
		}
		
		bool[] donea = new bool[n];
		bool[] doneb = new bool[n];
		
		Queue<int> q = new Queue<int>();
		for (int i = 0; i < n; ++i)
			if (b[i].Count == 1)
				q.Enqueue(i);
		
		while (q.Count > 0)
		{
			int bb = q.Dequeue();
			if (b[bb].Count == 0)
				return "0";
			
			int aa = b[bb][0];
			
			donea[aa] = true;
			doneb[bb] = true;
			
			foreach (int bbb in a[aa])
				if (bbb != bb)
			{
				b[bbb].Remove(aa);
				if (b[bbb].Count == 1)
					q.Enqueue(bbb);
			}
		}
		
		for (int i = 0; i < n; ++i)
			if (!doneb[i] && b[i].Count == 0)
				return "0";
		
		int res = 1;
		
		for (int i = 0; i < n; ++i)
			if (!donea[i])
		{
			res *= 2;
			res %= 1000003;
			
			donea[i] = true;
			q.Enqueue(i);
			
			while (q.Count > 0)
			{
				int aa = q.Dequeue();
				
				foreach (int bb in a[aa])
					foreach (int aaa in b[bb])
						if (!donea[aaa])
					{
						donea[aaa] = true;
						q.Enqueue(aaa);
					}
			}
		}
		
		return res.ToString();
	}
}
