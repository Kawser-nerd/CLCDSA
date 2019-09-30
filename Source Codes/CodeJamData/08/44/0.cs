using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace PermRLE
{
	class Program
	{
		private static string s;
		private static int k;

		private static int[,] cost;
		private static int[,] wrapCost;
		private static int[,] memo;

		static void Main(string[] args)
		{
//			StreamReader sr = new StreamReader(@"c:\temp\d-small-attempt0.in");
			StreamReader sr = new StreamReader(@"c:\temp\d-large.in");
//			StreamReader sr = new StreamReader(@"c:\temp\d.in");
//			TextWriter tw = Console.Out;
			StreamWriter tw = new StreamWriter(@"c:\temp\d-large.out");

			DateTime dt = DateTime.Now;
			int noCases = int.Parse(sr.ReadLine());
			for (int caseNo = 1; caseNo <= noCases; caseNo++)
			{
				Console.Error.WriteLine("Working on case " + caseNo);
				k = int.Parse(sr.ReadLine());
				s = sr.ReadLine();
				int noBlocks = s.Length/k;
				cost = new int[k,k];
				wrapCost = new int[k,k];
				for (int j = 0; j < k; j++)
				{
					for (int m = 0; m < k; m++)
					{
						for (int block = 0; block < noBlocks; block++)
						{
							if (s[block * k+j] != s[block * k +m])
								cost[j, m]++;
						}
						// j = first, m = last
						for (int block = 0; block < noBlocks - 1; block++)
						{
							if (s[block * k + m] != s[(block + 1) * k + j])
								wrapCost[j, m]++;
						}
					}
				}

				/*for (int i = 0; i < k; i++)
				{
					for (int j = 0; j < k; j++)
					{
						if (wrapCost[i,j] != wrapCost[j,i])
							throw new Exception();
					}
				}*/
                
				int best = int.MaxValue;
				for (int i = 0; i < k; i++)
				{
					memo = new int[k, 1 << k];

					int v = Run(1, i, i, (1 << k) - 1 - (1 << i));
					best = Math.Min(best, v);
				}
				tw.WriteLine("Case #" + caseNo + ": " + best);
			}
			tw.Close();
			Console.WriteLine((DateTime.Now - dt).TotalMilliseconds + " ms");
		}

		private static int Run(int pos, int first, int last, int leftMask)
		{
			if (pos == k)
				return wrapCost[first, last] + 1;
//				return wrapCost[last, first] + 1;
			if (memo[last, leftMask] > 0)
				return memo[last, leftMask];

			int best = int.MaxValue;
			for (int i = 0; i < k; i++)
			{
				if (((1<<i) & leftMask) == 0)
					continue;
				int c = cost[last, i] + Run(pos + 1, first, i, leftMask - (1 << i));
				best = Math.Min(best, c);
			}
			memo[last, leftMask] = best;
			return best;
		}
	}
}
