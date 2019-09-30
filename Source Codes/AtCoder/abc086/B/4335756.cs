using System;

namespace B
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var num = int.Parse(Console.ReadLine().Replace(" ", ""));
			for (var i = 1; i < num; i++)
			{
				if (i * i == num)
				{
					Console.WriteLine("Yes");
					return;
				}
			}

			Console.WriteLine("No");
		}
	}
}