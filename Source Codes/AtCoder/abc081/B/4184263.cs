using System;
using System.Linq;

namespace B
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var n = int.Parse(Console.ReadLine());
			var an = Console.ReadLine().Split().Select(int.Parse).ToList();

			for (var i = 0;; i++)
			{
				if (an.Any(a => a % 2 != 0))
				{
					Console.WriteLine(i);
					return;
				}

				an=an.ConvertAll(a => a /= 2);
			}
		}
	}
}