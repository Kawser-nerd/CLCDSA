using System;
using System.IO;

class Program
{
	public int getCount(string s)
	{
		int ret = 1;
		for (int i = 1; i < s.Length; i++)
			if (s[i] != s[i - 1]) ret++;
		return ret;
	}
	
	public int getBest(string s, int k)
	{
		int best = 999999;
		int[] p = new int[k];
		for (int i = 0; i < k; i++)
			p[i] = i;
		do {
			string t = "";
			for (int i = 0; i < s.Length; i++)
				t += s[(i / k) * k + p[i % k]];
			best = Math.Min(best, getCount(t));
		} while (nextPermutation(p));
		return best;
	}
	
	bool nextPermutation (int[] x) {
	for (int i = x.Length - 2; i >= 0; i--)
		if (x[i] < x[i + 1]) {
			Array.Reverse(x, i + 1, x.Length - i - 1);
			int j = i + 1;
			while (true) {
				if (x[i] < x[j]) {
					int t = x[i];
					x[i] = x[j];
					x[j] = t;
					return true;
				}
				j++;
			}
		}
	return false;
}

	
	public static void Main(string[] args)
	{
		StreamReader input = File.OpenText(@"f:\d-small.in");
		StreamWriter output = File.CreateText(@"f:\d-small.out");
		int c = Convert.ToInt32(input.ReadLine());
		for (int i = 1; i <= c; i++)
		{
			int k = Convert.ToInt32(input.ReadLine());
			string s = input.ReadLine();
			Program p = new Program();
			int ret = p.getBest(s, k);
			output.WriteLine("Case #" + i + ": " + ret);
		}
		input.Close();
		output.Close();
	}
}
