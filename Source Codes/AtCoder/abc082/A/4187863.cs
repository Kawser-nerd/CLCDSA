using System;
using System.Linq;

namespace A
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			Console.WriteLine((line[0] + line[1] + 1) / 2);
		}
	}
}