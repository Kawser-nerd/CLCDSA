using System;
class E { static void Main() { new K(); } }
class K
{
	public K()
	{
		var N = int.Parse(Console.ReadLine());
		var X = Console.ReadLine().Length;
		memo = new long[N + 1, N + 1];
		used = new bool[N + 1, N + 1];
		Console.WriteLine(Calc(N, X));
	}
	long[,] memo;
	bool[,] used;
	long Calc(int n, int x)
	{
		if (n == 0) return x == 0 ? 1 : 0;
		if (x > n) return 0;
		if (!used[n, x])
		{
			used[n, x] = true;
			memo[n, x] = (Calc(n - 1, x + 1) * 2 + Calc(n - 1, x == 0 ? x : x - 1)) % 1000000007;
		}
		return memo[n, x];
	}
}