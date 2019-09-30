using System;

namespace A
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var x = int.Parse(Console.ReadLine());
			var a = int.Parse(Console.ReadLine());
			var b = int.Parse(Console.ReadLine());

			Console.WriteLine(x - a - (x - a) / b * b);
		}
	}
}