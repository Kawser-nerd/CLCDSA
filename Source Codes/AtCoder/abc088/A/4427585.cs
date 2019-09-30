using System;

namespace A
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var n = int.Parse(Console.ReadLine());
			var a = int.Parse(Console.ReadLine());
			Console.WriteLine(a >= n % 500 ? "Yes" : "No");
		}
	}
}