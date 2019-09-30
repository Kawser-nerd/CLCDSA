using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemC
{
	static void Main(string[] args)
	{
		//TextReader sr = new StreamReader(@"c:\temp\c.in.txt");
		TextReader sr = new StreamReader(@"c:\temp\c-small-attempt0.in");
		//TextReader sr = new StreamReader(@"c:\temp\c-large.in");
		//		TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\c.out");
		//TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private static bool[,] Simulate(bool[,] b)
	{
		bool[,] a = new bool[100, 100];
		bool isEmpty = true;
		for(int y=0;y<100;y++)
			for (int x = 0; x < 100; x++)
			{
				if (b[y, x])
				{
					if ((y > 0 && b[y - 1, x]) || (x > 0 && b[y, x - 1]))
					{
						a[y, x] = true;
					}
				}
				else
				{
					if ((y > 0 && b[y - 1, x]) && (x > 0 && b[y, x - 1]))
					{
						a[y, x] = true;
					}
				}
				if (a[y, x])
					isEmpty = false;
			}
		if (isEmpty)
			return null;
		return a;
	}

	private static void Show(bool[,] b)
	{
		Console.WriteLine();
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
				if (b[y, x]) Console.Write('1'); else Console.Write('0');
			Console.WriteLine();
		}
		
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
		bool[,] bacteria = new bool[100, 100];
		int R = int.Parse(sr.ReadLine());
		for (int i = 0; i < R; i++)
		{
			var c = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
			int x1 = c[0], y1 = c[1], x2 = c[2], y2 = c[3];
			for (int y = y1; y <= y2; y++)
				for (int x = x1; x <= x2; x++)
					bacteria[y - 1, x - 1] = true;
		}

		int iterations = 0;
		while (bacteria != null)
		{
			//Show(bacteria);
			iterations++;
			bacteria = Simulate(bacteria);
		}
		sw.WriteLine(iterations);
	}
}
