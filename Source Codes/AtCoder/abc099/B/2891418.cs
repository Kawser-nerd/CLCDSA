using System;
using static System.Console;

namespace AtCorder
{
	public class Program
	{
		public static void Main()
		{
			var input = Array.ConvertAll(ReadLine().Split(), int.Parse);
			var d = input[1] - input[0];
			var ans = -input[0];
			for (int i = 1; i < d; i++)
			{
				ans += i;
			}
			WriteLine(ans);
		}
	}
}