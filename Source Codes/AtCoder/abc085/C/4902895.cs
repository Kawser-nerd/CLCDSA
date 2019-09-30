using System;

namespace algorithm
{
	class Program
	{
		
		static void Main(string[] args)
		{

			string[] s = Console.ReadLine().Split(' ');
			var N = int.Parse(s[0]);
			var Y = int.Parse(s[1]);
			for (int i = 0; i <= N; ++i)
			{
				for (int j = 0; j <= N - i; ++j)
				{
					var k = N - i - j;
					var sum = 10000 * i + 5000 * j + 1000 * k;
					if (sum == Y)
					{
						Console.WriteLine($"{i} {j} {k}");
						return;
					}
				}
			}
			Console.WriteLine("-1 -1 -1");
		}

	}
}