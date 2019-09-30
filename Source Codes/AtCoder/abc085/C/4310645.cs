using System;
using System.Linq;

namespace C
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var n = line[0];
			var y = line[1] / 1000;

			var a = -1;
			while (true)
			{
				a++;

				if (9 * a > y - n) { break; }

				if ((y - n - 9 * a) % 4 == 0)
				{
					var b = (y - n - 9 * a) / 4;
					if (a + b > n) { continue; }

					Console.WriteLine($"{a} {b} {n - a - b}");
					return;
				}
			}

			Console.WriteLine("-1 -1 -1");
		}
	}
}