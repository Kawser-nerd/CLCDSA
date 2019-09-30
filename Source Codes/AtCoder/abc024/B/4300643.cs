using System;
using System.Linq;

namespace B2
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var n = line[0];
			var t = line[1];
			var an = new int[n];
			for (var i = 0; i < n; i++) { an[i] = int.Parse(Console.ReadLine()); }

			var imosu = new int[1200000];
			foreach (var a in an)
			{
				imosu[a]++;
				imosu[a + t]--;
			}

			for (var i = 1; i < 1200000; i++) { imosu[i] += imosu[i - 1]; }

			Console.WriteLine(imosu.Count(i => i > 0));
		}
	}
}