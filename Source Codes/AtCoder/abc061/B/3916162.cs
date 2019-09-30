using System;

namespace ABC061_B_Counting_Roads
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int n = int.Parse(input[0]);
			int m = int.Parse(input[1]);
			
			int[] count = new int[n + 1]; //?????1???????+1
			for (int i = 1; i <= n; i++)
				count[i] = 0;
			
			for (int i = 0; i < m; i++)
			{
				input = Console.ReadLine().Split(' ');
				count[int.Parse(input[0])]++;
				count[int.Parse(input[1])]++;
			}
			
			for(int i = 1; i <= n; i++)
				Console.WriteLine(count[i]);
		}
	}
}