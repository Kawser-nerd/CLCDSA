using System;
using System.Collections.Generic;

namespace AtCoder
{
	public class Program
	{
		// ABC106-B
		static void Main(string[] args)
		{
			int N = int.Parse(Console.ReadLine());
			int result = 0;
			for (int i = 1; i <= N; i += 2) {
				int c = 0;
				for (int j = 1; j <= N; j += 2) {
					if (i%j==0) {
						c++;
					}
				}
				if (c == 8) {
					result++;
				}
			}
			Console.WriteLine(result);
		}
	}
}