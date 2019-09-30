using System;
using System.Linq;

namespace C
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var n = int.Parse(Console.ReadLine());
			var an = Console.ReadLine().Split().Select(int.Parse).ToArray();

			var result = an[0];
			for (var i = 1; i < n; i++) { result = GetGcd(result, an[i]); }

			Console.WriteLine(result);
		}

		private static int GetGcd(int a, int b)
		{
			if (b > a)
			{
				var tmp = a;
				a = b;
				b = tmp;
			}

			while (a % b != 0)
			{
				var tmp = a;
				a = b;
				b = tmp % b;
			}

			return b;
		}
	}
}