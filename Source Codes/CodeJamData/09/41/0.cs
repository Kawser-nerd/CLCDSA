using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemA
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\a.in");
//		TextReader sr = new StreamReader(@"c:\temp\a-small-attempt0.in");
		TextReader sr = new StreamReader(@"c:\temp\a-large.in");
		//		TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\a.out");
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
		int[] minRow = new int[n];
		for (int i = 0; i < n; i++)
		{
			string s = sr.ReadLine();
			minRow[i] = s.LastIndexOf('1');
		}
		int noSwaps = 0;
		for (int i = 0; i < n; i++)
		{
			int j = i;
			while (minRow[j] > i) j++;
			while (j > i)
			{
				noSwaps++;
				int tmp = minRow[j - 1];
				minRow[j - 1] = minRow[j];
				minRow[j] = tmp;
				j--;
			}
		}
		sw.WriteLine(noSwaps);
	}
}
