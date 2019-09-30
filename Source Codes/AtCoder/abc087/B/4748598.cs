using System;
using System.Text.RegularExpressions;

namespace algorithm
{
	class Program
	{
		static void Main(string[] args)
		{
			int i, j, k, l;

			i = int.Parse(Console.ReadLine());
			j = int.Parse(Console.ReadLine());
			k = int.Parse(Console.ReadLine());
			l = int.Parse(Console.ReadLine());
			int cnt = 0;
			for (int a = 0; a <= k; a++)
			{
				for (int b = 0; b<= j; b++)
				{
					for (int c = 0; c <= i; c++)
					{
						//???????
						if (a * 50 + b * 100 + c * 500 == l) cnt++;
					}

				}
			}

			Console.WriteLine(cnt);
		}
	}
}