using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

class Program
{
	int[,] dp;
	Dictionary<string, int> dp2 = new Dictionary<string, int>();
	int[] rx, ry;
	
	public class Point : IComparable
	{
		public int x, y;
		public Point(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
		public int CompareTo(object o)
		{
			Point p = (Point)o;
			if (y < p.y)
				return -1;
			if (y > p.y)
				return 1;
			if (x < p.x)
				return -1;
			if (x > p.x)
				return 1;
			return 0;
		}
	}
	
	public void calcdp(int y, int x)
	{
		dp[1, 1] = 1;
		for (int i = 1; i <= y; i++)
		{
			for (int j = 1; j <= x; j++)
			{
				if (i > 2 && j > 1)
					dp[i, j] += dp[i - 2, j - 1];
				if (i > 1 && j > 2)
					dp[i, j] += dp[i - 1, j - 2];
				dp[i, j] = dp[i, j] % 10007;
				for (int k = 0; k < rx.Length; k++)
				{
					if (rx[k] == j && ry[k] == i)
						dp[i, j] = 0;
				}
			}
				
		}
		
	}
	
	public int go(int y, int x)
	{
		return dp[y, x];
	}
	
	public int calculate(int sr, int sc, int r, int c, int mask)
	{
		for (int i = 0; i < rx.Length; i++)
		{
			if ((mask & (1 << i)) > 0)
			{
				if (rx[i] == sc && ry[i] == sr)
					return 0;
				if (rx[i] == c && ry[i] == c)
					return 0;
			}
		}
		if (sr == r && sc == c) return 1;
		if (sr > r || sc > c) return 0;
		
		string key = sr + " " + sc + " " + r + " " + c + " " + mask;
		if (dp2.ContainsKey(key))
			return dp2[key];
		int r1 = go(1 + r - sr, 1 + c - sc);
		//Console.WriteLine(key + " " + r1);
		for (int i = 0; i < rx.Length; i++)
			if ((mask & (1 << i)) > 0 && ry[i] <= r && rx[i] <= c && ry[i] >= sr && rx[i] >= sc)
		{
				int x1 = calculate(1, 1, ry[i], rx[i], mask - (1 << i));
				int x2 = calculate(ry[i], rx[i], r, c, mask - (1 << i));
				r1 -= (x1 * x2) % 10007;
		}
		while (r1 < 0) r1 += 10007;
		while (r1 > 10007) r1 -= 10007;
		dp2.Add(key, r1);
		return r1;
	}
	
	public static void Main(string[] args)
	{
		StreamReader input = File.OpenText(@"f:\d-small.in");
		StreamWriter output = File.CreateText(@"f:\d-small.out");
		int c = Convert.ToInt32(input.ReadLine());
		for (int i = 1; i <= c; i++)
		{
			Console.WriteLine(i);
			string[] s = input.ReadLine().Split(' ');
			int h = Convert.ToInt32(s[0]);
			int w = Convert.ToInt32(s[1]);
			int r = Convert.ToInt32(s[2]);
			int[] rx = new int[r];
			int[] ry = new int[r];
			for (int j = 0; j < r; j++)
			{
				string[] t = input.ReadLine().Split(' ');
				ry[j] = Convert.ToInt32(t[0]);
				rx[j] = Convert.ToInt32(t[1]);
			}

			Program p = new Program();
			p.rx = rx;
			p.ry = ry;
			p.dp = new int[h + 1, w + 1];
			p.calcdp(h, w);
			
			//int ret = p.calculate(1, 1, h, w, (1 << rx.Length) - 1);
			
			output.WriteLine("Case #" + i + ": " + p.dp[h, w]);
		}
		input.Close();
		output.Close();
		Console.ReadLine();
	}
}
