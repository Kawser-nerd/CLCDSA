using System;

namespace B
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var a = int.Parse(Console.ReadLine());
			var b = int.Parse(Console.ReadLine());
			var c = int.Parse(Console.ReadLine());
			var x = int.Parse(Console.ReadLine()) / 50;

			var result = 0;
			for (var aNum = 0; aNum <= x / 10 && aNum <= a; aNum++)
			{
				var diffWithX = x - aNum * 10;
				for (var bNum = 0; bNum <= diffWithX / 2 && bNum <= b; bNum++)
				{
					if (diffWithX - bNum * 2 <= c) { result++; }
				}
			}

			Console.WriteLine(result);
		}
	}
}