using System;

static class Solution
{
	// http://olsen.org/alan/blog/?p=85
	/*
	 * Transitions perm to the next lexigraphical permutation and
	 * returns true, unless it is the last permutation, in which case
	 * it resets to the first permutation and returns false
	 */
	static bool next_permutation(int[] perm)
	{
		int n = perm.Length;
		int k = -1;
		for (int i = 1; i < n; i++)
			if (perm[i - 1] < perm[i])
				k = i - 1;
		if (k == -1)
		{
			for (int i = 0; i < n; i++)
				perm[i] = i;
			return false;
		}

		int l = k + 1;
		for (int i = l; i < n; i++)
			if (perm[k] < perm[i])
				l = i;

		int t = perm[k];
		perm[k] = perm[l];
		perm[l] = t;

		Array.Reverse(perm, k + 1, perm.Length - (k + 1));

		return true;
	}
	
	static void Main()
	{
		var T = Convert.ToInt32(Console.ReadLine());
		for (var iT = 1; iT <= T; ++iT)
		{
			var N = Convert.ToInt32(Console.ReadLine());
			var cars = Console.ReadLine().Split();
			
			var perm = new int[N];
			for (var i = 0; i < N; ++i)
				perm[i] = i;
			
			int answer = check(perm, cars) ? 1 : 0;
			while (next_permutation(perm))
				answer += check(perm, cars) ? 1 : 0;
			Console.WriteLine("Case #{0}: {1}", iT, answer);
		}
	}
	
	static bool check(int[] perm, string[] cars)
	{
		var used = new bool[26];
		char last = ' ';
		foreach (int i in perm)
		{
			string car = cars[i];
			foreach (char c in car)
			{
				if (c != last)
				{
					if (used[c - 'a'])
						return false;
					used[c - 'a'] = true;
					last = c;
				}
			}
		}
		return true;
	}
}