using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2009
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("B-large.in");
            string output = "";
            int lineAt = 0;
			int C = int.Parse(input[lineAt++]);
			for (int i = 0; i < C; i++)
			{
				string[] cases = input[lineAt++].Split(' ');
				int N = int.Parse(cases[0]);
				int K = int.Parse(cases[1]);
				int B = int.Parse(cases[2]);
				int T = int.Parse(cases[3]);
				List<int> x = new List<int>();

				string[] xs = input[lineAt++].Split(' ');
				for (int j = 0; j < N; j++)
				{
					x.Add(int.Parse(xs[j]));
				}
				List<int> v = new List<int>();
				string[] vs = input[lineAt++].Split(' ');
				for (int j = 0; j < N; j++)
				{
					v.Add(int.Parse(vs[j]));
				}
				List<double> arrivalTimes = new List<double>();
				for (int j = 0; j < N; j++)
				{
					arrivalTimes.Add((B - x[j]) / ((double)v[j]));
				}
				int make = 0;
				bool[] canMake = new bool[N];
				for (int j = 0; j < N; j++)
				{
					if (arrivalTimes[j] <= T)
					{
						canMake[j] = true;
						make++;
					}
				}
				string res = 0.ToString();
				if (make < K)
				{
					res = "IMPOSSIBLE";
				}
				else
				{
					int done = 0;
					int need = 0;
					int inTheWay = 0;
					for (int k = N - 1; k >= 0; k--)
					{
						if (done == K) break;
						if (!canMake[k])
						{
							inTheWay++;
						}
						else
						{
							need += inTheWay;
							done++;
						}
					}
					res = need.ToString();
				}
				
				output += "Case #" + (i + 1) + ": " + res + Environment.NewLine;
			}
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
    }
}
