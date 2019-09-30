using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	
	class Program
	{
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("C-small-attempt0.in");
			int lineat = 0;
			int count = int.Parse(lines[lineat++]);
			string output = "";
			for (int i = 0; i < count; i++)
			{
				string[] l = lines[lineat++].Split(' ');
				int m = int.Parse(l[0]);
				int q = int.Parse(l[1]);
				double[,] probabilities = new double[q, 4];
				for (int j = 0; j < q; j++)
				{
					string[] what = lines[lineat++].Split(' ');
					for (int k = 0; k < 4; k++)
					{
						probabilities[j, k] = double.Parse(what[k]);
					}
				}
				Program p = new Program();
				p.probs = probabilities;
				p.q = q;
				p.go(0, 1);
				p.res.Sort();
				p.res.Reverse();
				m = Math.Min(m, p.res.Count);
				double answer = 0;
				double mult = 1;
				for (int j = 0; j < m; j++)
				{
					answer += mult * p.res[j];
					//mult *= (1 - p.res[j]);
				}
				output += "Case #" + (i + 1) + ": " + answer + Environment.NewLine;
			}
			File.WriteAllText("output.txt", output);
			Console.WriteLine(output);
		}
		double[,] probs;
		int q;
		List<double> res = new List<double>();
		void go(int at,double p)
		{
			if (at == q)
			{
				res.Add(p);
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					go(at + 1, p * probs[at, i]);
				}
			}
		}
	}
}
