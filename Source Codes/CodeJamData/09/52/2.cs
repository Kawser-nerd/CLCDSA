using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemB
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\b.in");
		TextReader sr = new StreamReader(@"c:\temp\b-small-attempt0.in");
//		TextReader sr = new StreamReader(@"c:\temp\b-large.in");
//				TextReader sr = Console.In;
				TextWriter sw = new StreamWriter(@"c:\temp\b.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			Console.WriteLine("Case #" + caseNo);
			sw.Write("Case #" + caseNo + ": ");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private class Poly
	{
		public int[] Var;
		public int Eval(int[] freq)
		{
			int q = 1;
			foreach(int v in Var)
			{
				q = (q*freq[v])%MOD;
			}
			return q;
		}
	}

	private static Poly[] poly;
	private static int k, noTerms, noWords;
	private static int[] sum;
	private static int[,] wordLetterCount;
	private const int MOD = 10009;

	static void Count(int[] freq, int w)
	{
		if (w >= k) return;
		for (int i = 0; i < noWords; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				freq[j] += wordLetterCount[i, j];
			}

			int eval = 0;
			for (int j = 0; j < noTerms; j++)
			{
				eval = (eval + poly[j].Eval(freq))%MOD;
			}
			sum[w] = (sum[w] + eval)%MOD;
			Count(freq, w + 1);
			for (int j = 0; j < 26; j++)
			{
				freq[j] -= wordLetterCount[i, j];
			}
		}
		
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
		string[] line = sr.ReadLine().Split(' ');
		k = int.Parse(line[1]);
		string[] terms = line[0].Split('+');
		noTerms = terms.Length;
		poly = new Poly[noTerms];
		for (int i = 0; i < noTerms; i++)
		{
			poly[i] = new Poly();
			poly[i].Var = new int[terms[i].Length];
			for (int j = 0; j < terms[i].Length; j++)
			{
				poly[i].Var[j] = terms[i][j] - 'a';
			}
		}
		noWords = int.Parse(sr.ReadLine());
		wordLetterCount = new int[noWords,26];
		for (int i = 0; i < noWords; i++)
		{
			string s = sr.ReadLine();
			for (int j = 0; j < s.Length; j++)
			{
				wordLetterCount[i, s[j] - 'a']++;
			}
		}
		sum = new int[k + 1];
		Count(new int[26], 0);
		for (int i = 0; i < k; i++)
		{
			if (i>0) sw.Write(' ');
			sw.Write(sum[i]);
		}
		sw.WriteLine();
	}
}
