using System;
using System.Collections.Generic;
using System.Linq;

namespace arc073_b
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			long minw = 0;
			List<int> k1 = new List<int>(); List<int> k2 = new List<int>();
			List<int> k3 = new List<int>(); List<int> k4 = new List<int>();
			for (int i = 0; i < x[0]; i++)
			{
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				if (i == 0)
				{
					minw = a[0]; k1.Add(a[1]);
					continue;
				}
				switch (a[0] - minw)
				{
					case 0: { k1.Add(a[1]); break; }
					case 1: { k2.Add(a[1]); break; }
					case 2: { k3.Add(a[1]); break; }
					case 3: { k4.Add(a[1]); break; }
				}
			}
			int[] a1 = k1.ToArray(); Array.Sort(a1); Array.Reverse(a1);
			int[] a2 = k2.ToArray(); Array.Sort(a2); Array.Reverse(a2);
			int[] a3 = k3.ToArray(); Array.Sort(a3); Array.Reverse(a3);
			int[] a4 = k4.ToArray(); Array.Sort(a4); Array.Reverse(a4);
			long[] s1 = new long[a1.Length + 1];
			for (int i = 0; i < a1.Length; i++) s1[i + 1] = s1[i] + a1[i];
			long[] s2 = new long[a2.Length + 1];
			for (int i = 0; i < a2.Length; i++) s2[i + 1] = s2[i] + a2[i];
			long[] s3 = new long[a3.Length + 1];
			for (int i = 0; i < a3.Length; i++) s3[i + 1] = s3[i] + a3[i];
			long[] s4 = new long[a4.Length + 1];
			for (int i = 0; i < a4.Length; i++) s4[i + 1] = s4[i] + a4[i];
			long ret = 0;
			for (int i = 0; i < s1.Length; i++)
			{
				for (int j = 0; j < s2.Length; j++)
				{
					for (int k = 0; k < s3.Length; k++)
					{
						for (int l = 0; l < s4.Length; l++)
						{
							if (minw * i + (minw + 1) * j + (minw + 2) * k + (minw + 3) * l <= x[1])
							{
								ret = Math.Max(ret, s1[i] + s2[j] + s3[k] + s4[l]);
							}
						}
					}
				}
			}
			Console.WriteLine(ret);
		}
	}
}