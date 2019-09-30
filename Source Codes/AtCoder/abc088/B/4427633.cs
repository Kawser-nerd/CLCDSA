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
			an.Sort();
			an.Reverse();
			var alice = 0;
			var bob = 0;
			for (var i = 0; i < n; i++)
			{
				if (i % 2 == 0) { alice += an[i]; }
				else { bob += an[i]; }
			}

			Console.WriteLine(alice - bob);
		}
	}
}