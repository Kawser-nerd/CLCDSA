using System;
using System.Collections.Generic;

namespace AtCoder
{
	public class Program
	{
		// ABC105-B
		static void Main(string[] args)
		{
			int N = int.Parse(Console.ReadLine());

			// cake = 4;
			// donuts = 7;
			for (int cake = N / 4; cake >= 0; cake--) {
				int donuts = (N - (cake * 4)) / 7;
				if (cake * 4 + donuts * 7 == N) {
					//Console.WriteLine(cake + "*4 + " + donuts + "*7 = " + N);
					Console.WriteLine("Yes");
					return;
				}
			}
			Console.WriteLine("No");
		}
	}
}