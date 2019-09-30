using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Library;
using Library.Extensions;

namespace Competition
{
	class Class3
	{
		public void Arg()
		{
			var file = System.IO.File.ReadAllLines(@"C:\Users\root\Documents\Downloads\C-small-attempt2.in");
//            var file2 = @"2
//8 1
//3
//20 3
//3 6 14";
//            var file = file2.Replace("\r", "").Split('\n');

			int line = 0;
			int cases = int.Parse(file[line++]);

			var sb = new System.Text.StringBuilder();
			for (int c = 1; c <= cases; c++)
			{
				var ln = file[line++].Split(' ');
				int P = int.Parse(ln[0]);
				int Q = int.Parse(ln[1]);

				var prisoners = file[line++].Split(' ').Convert(x=>int.Parse(x)-1);

				int[] tempPris = new int[Q];
				//just do brute for now
				long small = long.MaxValue;
				foreach (int[] order in Perms(Q))
				{
					for (int i = 0; i < order.Length; i++) tempPris[i] = prisoners[order[i]];

					long res = Eval(tempPris, P);
					if (res < small) small = res;
				}

				sb.AppendFormat("Case #{0}: {1}", c, small);
				sb.AppendLine();
			}

			System.IO.File.WriteAllText(@"C:\Pub\c.txt", sb.ToString());
		}

		public IEnumerable<int[]> Perms(int size)
		{
			if (size == 1)
			{
				yield return new int[] { 0 };
				yield break;
			}

			int[] rtn = new int[size];
			//Stupid perm for now
			while (Combinatorics.Increment(rtn, size))
			{
				if (rtn.Distinct().Count() == size) yield return rtn;
			}
		}

		private long Eval(int[] pris, int Q)
		{
			bool[] stupid = new bool[Q];
			long res = 0;
			for (int i = 0; i < pris.Length; i++)
			{
				int c = pris[i];
				stupid[c] = true;

				for (int j = c-1; j >= 0; j--)
				{
					if (stupid[j])
						break;
					res++;
				}

				for (int j = c+1; j < stupid.Length; j++)
				{
					if (stupid[j])
						break;
					res++;
				}
			}

			return res;
		}
	}
}
