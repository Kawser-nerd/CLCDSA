using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace GCJ2008
{
	class Numbers
	{
		static int[,] lut = new int[11, 30000000];
				
		// 0 unknown, 1 visited, 2 false, 3 true
		static int go(int n, int b)
		{
			if (n == 1)
			{
				return 3;
			}
			if (lut[b, n] == 0)
			{
				lut[b, n] = 1;
				int acc = 0;
				int nn = n;
				while (nn > 0)
				{
					int sqr = nn % b;
					nn /= b;
					acc += sqr * sqr;
				}
				lut[b, n] = go(acc, b);
			}
			return lut[b, n];
		}
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("A-large.in");
			int lineAt = 0;
			string output = "";

			int cases = int.Parse(lines[lineAt++]);
			for (int i = 0; i < cases; i++)
			{
				List<int> bases = new List<int>();
				string[] num = lines[lineAt++].Split(' ');
				for (int j = 0; j < num.Length; j++)
				{
					bases.Add(int.Parse(num[j]));
				}
				for (int j = 2; j < int.MaxValue; j++)
				{
					bool happy = true;
					for (int k = 0; k < bases.Count; k++)
					{
						int b = bases[k];
						if(go(j, b) != 3)
						{
							happy = false;
							break;
						}
					}
					if (happy)
					{

						output += "Case #" + (i + 1) + ": " + j;
						output += Environment.NewLine;
						break;
					}
				}
				
			}
			Console.WriteLine(output);
			File.WriteAllText("output.txt", output);
		}
		static double choose(double a, double b)
		{
			double acc = 1;
			for (int i = 1; i < a - b; i++)
			{
				acc *= a - i;
				acc /= i;
			}
			return acc;
		}
	}
}
