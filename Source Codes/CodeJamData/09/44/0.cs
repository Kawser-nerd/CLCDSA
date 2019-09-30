using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemD
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\d.in");
		TextReader sr = new StreamReader(@"c:\temp\d-small-attempt0.in");
//					TextReader sr = new StreamReader(@"c:\temp\d-large.in");
		//		TextReader sr = Console.In;
							TextWriter sw = new StreamWriter(@"c:\temp\d.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
		int n = int.Parse(sr.ReadLine());
		int[] x = new int[n], y = new int[n], r = new int[n];
		for (int i = 0; i < n; i++)
		{
			string[] line = sr.ReadLine().Split(' ');
			x[i] = int.Parse(line[0]);
			y[i] = int.Parse(line[1]);
			r[i] = int.Parse(line[2]);
		}
		if (n == 1)
		{
			sw.WriteLine(r[0]);
		}
		else if (n == 2)
		{
			sw.WriteLine(Math.Max(r[0], r[1]));
		}
		else if (n == 3)
		{
			double best = double.MaxValue;
			for (int i = 0; i < 3; i++)
			{
				double r1 = r[i];
				for (int a = 0; a < 3; a++)
				{
					for (int b = a + 1; b < 3; b++)
					{
						if (a != i && b != i)
						{
							int dx = x[a] - x[b], dy = y[a] - y[b];
							double dist = Math.Sqrt(dx*dx + dy*dy);
							double r2 = dist + r[a] + r[b];
							best = Math.Min(best, Math.Max(r1, r2) / 2.0);
						}
					}
				}
				
			}
			sw.WriteLine(string.Format(CultureInfo.InvariantCulture, "{0:0.0000000}", best));
		}
		else
		{
			sw.WriteLine(0);
		}
	}
}