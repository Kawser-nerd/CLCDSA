using System;
using System.IO;

class Program
{
	public int[] getTriangle(int n, int m, int a)
	{
		int x = (int)Math.Sqrt(a);
		for (int j = x; j >= 1; j--)
			if (j <= n && a % j == 0 && a / j <= m)
				return new int[]{0, 0, j, 0, j, a / j};
		
		/*
		for (int xx = 1; xx <= n; xx++)
		{
			for (int yy = 0; yy <= m; yy++)
			{
				for (int xx2 = 0; xx2 <= n; xx2++)
				{
					int c = a + 2 * xx2 * yy;
					if (c % (2 * xx) == 0)
					{
						int yy2 = (a + 2 * xx2 * yy) / (2 * xx);
						if (yy2 <= m)
							return new int[]{0, 0, xx, yy, xx2, yy2};
					}
				}
			}
		}
		*/
		for (int x2 = 0; x2 <= n; x2++)
		{
			for (int y2 = 0; y2 <= m; y2++)
			{
				for (int x3 = 0; x3 <= n; x3++)
				{
					for (int y3 = 0; y3 <= m; y3++)
					{
						if (Math.Abs(x2 * y3 - x3 * y2) == a)
							return new int[]{0, 0, x2, y2, x3, y3};
					}					
				}				
			}
		}
		
		
		return new int[]{-1, -1, -1};
	}
	
	public static void Main(string[] args)
	{
		StreamReader input = File.OpenText(@"f:\b-small.in");
		StreamWriter output = File.CreateText(@"f:\b-small.out");
		int c = Convert.ToInt32(input.ReadLine());
		for (int i = 1; i <= c; i++)
		{
			string[] s = input.ReadLine().Split(' ');
			int n = Convert.ToInt32(s[0]);
			int m = Convert.ToInt32(s[1]);
			int a = Convert.ToInt32(s[2]);			
			Program p = new Program();
			int[] ret = p.getTriangle(n, m, a);
			if (ret[0] == -1)
			{
				output.WriteLine("Case #" + i + ": IMPOSSIBLE");
			}
			else
			{
				output.WriteLine("Case #" + i + ": " + ret[0] + " " + ret[1] + " " + ret[2] + " " + ret[3] + " " + ret[4] + " " + ret[5]);
			}
		}
		input.Close();
		output.Close();
	}
}
