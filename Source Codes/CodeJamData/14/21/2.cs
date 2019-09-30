using System;
using System.Collections.Generic;

public class A
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		for(int testcase = 1; testcase <= tests; testcase++)
		{
			Console.Write("Case #{0}: ", testcase);
			int n = int.Parse(Console.ReadLine());
			string[] ss = new string[n];
			for(int i = 0; i < n; i++)
				ss[i] = Console.ReadLine();
			
			List<Pair>[] splits = new List<Pair>[n];
			for(int i = 0; i < n; i++)
				splits[i] = split(ss[i]);

			bool ok = true;
			int sum = 0;
			for(int i = 1; ok && i < n; i++)
			{
				if(splits[i].Count != splits[0].Count) ok = false;
				for(int j = 0; ok && j < splits[0].Count; j++)
				{
					if(splits[i][j].a != splits[0][j].a)
						ok = false;
				}
			}
			
			if(ok)
			{
				
				for(int i = 0; i < splits[0].Count; i++)
				{
					int best = -1;
					for(int k = 1; k <= 100; k++)
					{
						int cur = 0;
						for(int j = 0; j < n; j++)
						{
							cur += Math.Abs(splits[j][i].count - k);
						}
						if(best == -1 || cur < best) best = cur;
					}
					sum += best;
				}
			}

			if(ok)
				Console.WriteLine(sum);
			else
				Console.WriteLine("Fegla Won");
		}
	}

	public static List<Pair> split(string s)
	{
		char cura = s[0];
		int count = 1;
		List<Pair> ret = new List<Pair>();
		for(int i = 1; i < s.Length; i++)
		{
			if(s[i] == cura) count++;
			else
			{
				ret.Add(new Pair(cura, count));
				cura = s[i];
				count = 1;
			}
		}
		ret.Add(new Pair(cura, count));
		return ret;
	}

	public class Pair
	{
		public char a;
		public int count;

		public Pair(char a, int c)
		{
			this.a = a;
			this.count = c;
		}
	}
}