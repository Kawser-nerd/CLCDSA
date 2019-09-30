using System;
using System.Collections.Generic;

public class C
{
	static int[] q;
	static int qn;
	
	static void init (int n)
	{
		qn = 1;
		
		while (qn <= n)
			qn *= 2;
		
		q = new int[qn * 2];
	}
	
	static int empty (int qfrom, int qto, int node, int from, int to)
	{
//		Console.WriteLine ("empty: {0} {1} {2} {3} {4} {5}", qfrom, qto, node, from, to, q[node]);
		
		if (qfrom == from && qto == to)
			return q[node];
		
		int qmid = (qfrom + qto) / 2;
		
		if (to <= qmid)
			return empty (qfrom, qmid, 2 * node, from, to);
		else if (from > qmid)
			return empty (qmid + 1, qto, 2 * node + 1, from, to);
		else
			return empty (qfrom, qmid, 2 * node, from, qmid) + empty (qmid + 1, qto, 2 * node + 1, qmid + 1, to);
	}
	
	static int empty (int from, int to)
	{
		return 1 + to - from - empty (0, qn - 1, 1, from, to);
	}
	
	static void used (int qfrom, int qto, int node, int i)
	{
		q[node]++;
		
		if (qfrom == qto)
			return;
		
		int qmid = (qfrom + qto) / 2;
		
		if (i <= qmid)
			used (qfrom, qmid, 2 * node, i);
		else
			used (qmid + 1, qto, 2 * node + 1, i);
	}
	
	static void used (int i)
	{
		used (0, qn - 1, 1, i);
	}
	
	public static void Main ()
	{
		int N = int.Parse (Console.ReadLine ());
		
		for (int I = 1; I <= N; ++I)
		{
			int n = int.Parse (Console.ReadLine ());
			init (n);
			
			int[] res = new int[n];
			int now = 0;
			
			for (int i = 1; i <= n; ++i)
			{
//				Console.WriteLine ("Lookup {0}", i);
				
				int skip = (i - 1) % (1 + n - i);
				int toend = empty (now, n - 1);
				
				if (skip >= toend)
				{
					skip -= toend;
					now = 0;
				}
				
				int max = n - 1;
				
				while (now < max)
				{
					int mid = (now + max) / 2;
					int emp = empty (now, mid);
					if (skip >= emp)
					{
						now = mid + 1;
						skip -= emp;
					}
					else
						max = mid;
				}
				
//				Console.WriteLine ("Now is {0}", now);
				
				res[now] = i;
				used (now);
			}
			
			
			Console.Write ("Case #{0}:", I);
			
			string[] s = Console.ReadLine ().Split (' ');
			for (int i = 1; i < s.Length; ++i)
				Console.Write (" {0}", res[int.Parse (s[i]) - 1]);
			
			Console.WriteLine ();
		}
	}
}
