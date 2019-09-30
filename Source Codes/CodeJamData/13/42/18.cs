using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class B
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] p = Console.ReadLine().Split();
			int N = int.Parse(p[0]);
			long P = long.Parse(p[1]);
			long g = Guaranteed(N, P);
			long c = Could(N, P);
			if (c < g) throw new Exception();
			Console.WriteLine("Case #" + CASE + ": " + g + " " + c);
		}
	}

	public static long Guaranteed(int N, long P)
	{
		/*
		for (long i = 0; i < (1L << N); i++)
			if (!WilWin(i, N, P))
				return i - 1;
		return (1L << N);
		 * */
		long teams = 1L << N;
		return teams - Could(N, teams - P) - 2;
	}

	public static bool WilWin(long i, int N, long P)
	{
		long half = 1L << (N - 1);
		if (P <= 0) return false;
		if (i == 0) return true;
		if (i == 1)
			return P > half;
		return WilWin(i - 2, N / 2, P - half);
	}

	public static long Could(int N, long P)
	{
		for (long i = (1L << N) - 1; i >= 0; i--)
			if (CouldWin(i, N, P))
				return i;
		return -1;
	}

	public static bool CouldWin(long i, int N, long P)
	{
		long half = 1L << (N - 1);
		if (P <= 0) return false;
		if (i == 0) return true;
		if (N == 0) return false;
		if ((i & 1) > 0)
			return CouldWin(i / 2, N - 1, P - half);
		return CouldWin(i / 2, N - 1, P);
	}

}
