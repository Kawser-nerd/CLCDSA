using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] parts = Console.ReadLine().Split();
			R = int.Parse(parts[0]);
			C = int.Parse(parts[1]);
			W = int.Parse(parts[2]);
			if (R > 1) throw new Exception();
			done = new bool[1 << C, 1 << C];
			mem = new int[1 << C, 1 << C];
			Console.WriteLine("Case #" + CASE + ": " + rec(0, 0));
		}
	}

	public static int W, R, C;
	public static bool[,] done;
	public static int[,] mem;

	public static int rec(int hit, int miss)
	{
		if (done[hit, miss]) return mem[hit, miss];
		done[hit, miss] = true;
		if (bitcount(hit) == W)
			return mem[hit, miss] = 0;
		mem[hit, miss] = 999;

		for (int i = 0; i < C; i++)
		{
			if ((hit & (1 << i)) > 0) continue;
			if ((miss & (1 << i)) > 0) continue;
			mem[hit, miss] = Math.Min(mem[hit, miss], rec2(i, hit, miss) + 1);
		}

		return mem[hit, miss];
	}
	
	public static int rec2(int x, int hit, int miss)
	{
		int ans = -1;
		for (int i = 0; i <= C - W; i++)
		{
			bool ok = true;
			for (int j = 0; j < C; j++)
			{
				if ((hit & (1 << j)) > 0 && (j < i || j >= i + W)) ok = false;
				if ((miss & (1 << j)) > 0 && (i <= j && j < i + W)) ok = false;
			}
			if (ok && i <= x && x < i + W)
				ans = Math.Max(ans, rec(hit | (1 << x), miss));
			else if (ok)
				ans = Math.Max(ans, rec(hit, miss | (1 << x)));
		}

		if (ans == -1) throw new Exception();
		return ans;
	}

	public static int bitcount(int x)
	{
		int ans = 0;
		while (x > 0)
		{
			ans += x & 1;
			x >>= 1;
		}
		return ans;
	}
}
