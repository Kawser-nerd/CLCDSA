using System;
using System.IO;

class Program
{
	public long minimum(long[] x, long[] y)
	{
		Array.Sort(x);
		Array.Sort(y);
		long ret = 0;
		for (int i = 0; i < x.Length; i++)
			ret += x[i] * y[y.Length - i - 1];
		return ret;
	}
	
	public static void Main(string[] args)
	{
		StreamReader input = File.OpenText(@"F:\a-large.in");
		StreamWriter output = File.CreateText(@"F:\a-large.out");
		int c = Convert.ToInt32(input.ReadLine());
		for (int i = 1; i <= c; i++)
		{
			int n = Convert.ToInt32(input.ReadLine());
			string[] xx = input.ReadLine().Split(' ');
			string[] yy = input.ReadLine().Split(' ');
			long[] x = new long[xx.Length];
			long[] y = new long[yy.Length];
			for (int j = 0; j < xx.Length; j++)
				x[j] = Convert.ToInt64(xx[j]);
			for (int j = 0; j < yy.Length; j++)
				y[j] = Convert.ToInt64(yy[j]);
			Program test = new Program();
			long ret = test.minimum(x, y);
			output.WriteLine("Case #" + i + ": " + ret);
		}
		input.Close();
		output.Close();
	}
}
