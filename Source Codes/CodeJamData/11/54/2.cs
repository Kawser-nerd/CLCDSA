using System;
using System.Collections.Generic;
using System.Linq;

public class MainClass
{
	public static void Main (string[] args)
	{
		MainClass task = new MainClass();
		
		int n = int.Parse(Console.ReadLine());
		for(int i = 1; i <= n; ++i)
			Console.WriteLine("Case #{0}: {1}", i, task.Solve());
	}
	
	long rec(long num, int[] pos, int now)
	{
		if (now == pos.Length)
		{
			long q = (long)Math.Sqrt(num);
			while (q * q > num)
				--q;
			while (q * q < num)
				++q;
			if (q * q == num)
				return num;
			else
				return -1;
		}
		
		long r;
		
		r = rec(num, pos, now + 1);
		if (r != -1)
			return r;
		r = rec(num | (1L << pos[now]), pos, now + 1);
		return r;
	}
	
	public string Solve()
	{
		string s = new string(Console.ReadLine().Reverse().ToArray());
		long num = 0;
		
		List<int> x = new List<int>();
		
		for (int i = 0; i < s.Length; ++i)
		{
			if (s[i] == '1')
				num += (1L << i);
			else if (s[i] != '0')
				x.Add(i);
		}
		
		long res = rec(num, x.ToArray(), 0);
		string ret = "";
		while (res > 0)
		{
			if (res % 2 == 0)
				ret = "0" + ret;
			else
				ret = "1" + ret;
			
			res /= 2;
		}
		
		return ret;
	}
}
