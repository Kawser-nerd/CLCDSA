using System;

namespace agc024_b
{
	class Program
	{
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			int[] x = new int[n];
			for (int i = 0; i < n; i++)
			{
				x[int.Parse(Console.ReadLine()) - 1] = i;
			}
			int max = 1; int len = 1;
			for (int i = 1; i < n; i++)
			{
				if (x[i] > x[i - 1]) len++;
				else { max = Math.Max(max, len); len = 1; }
			}
			Console.WriteLine(n - Math.Max(max, len));
		}
	}
}