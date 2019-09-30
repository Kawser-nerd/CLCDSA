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
//		TextReader sr = new StreamReader(@"c:\temp\b-small-attempt0.in");
		TextReader sr = new StreamReader(@"c:\temp\b-large.in");
//				TextReader sr = Console.In;
//				TextWriter sw = new StreamWriter(@"c:\temp\b-small.out");
				TextWriter sw = new StreamWriter(@"c:\temp\b-large.out");
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
		string N = sr.ReadLine();

		char[] t = N.ToCharArray();
		if (NextPermutation(t))
		{
			string s = "";
			foreach(char b in t)
			{
				s += b;
			}
			sw.WriteLine(s);
			return;
		}
		
		Array.Sort(t);
		int firstNonZero = 0;
		while (t[firstNonZero] == '0') firstNonZero++;
		sw.Write(t[firstNonZero] + "0");
		for (int i = 0; i < firstNonZero; i++)
		{
			sw.Write("0");
		}
		for (int i = firstNonZero + 1; i < t.Length; i++)
		{
			sw.Write(t[i]);
		}
		sw.WriteLine();
	}

	public static bool NextPermutation<T>(T[] array)
			where T : IComparable<T>
	{
		return NextPermutation(array, 0, array.Length);
	}

	public static bool NextPermutation<T>(T[] array, int begin, int end)
		where T : IComparable<T>
	{
		if (begin == end)
			return false;

		int i = begin + 1;
		if (i == end)
			return false;
		i = end - 1;

		while (true)
		{
			int ii = i--;
			if (array[i].CompareTo(array[ii]) < 0)
			{
				int j = end;
				while (!(array[i].CompareTo(array[--j]) < 0)) ;

				T tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				Reverse(array, ii, end);
				return true;
			}
			if (i == 0)
			{
				Reverse(array, 0, end);
				return false;
			}
		}
	}

	public static void Reverse<T>(T[] array, int begin, int end)
	{
		for (int i = 0; i < (end - begin) / 2; i++)
		{
			T tmp = array[begin + i];
			array[begin + i] = array[end - i - 1];
			array[end - i - 1] = tmp;
		}
	}
	
}
