using System;
using System.Linq;

namespace A2
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var a = line[0];
			var b = line[1];
			var c = line[2];
			var k = line[3];
			line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var s = line[0];
			var t = line[1];

			Console.WriteLine(s * a + t * b - (s + t < k ? 0 : (s + t) * c));
		}
	}
}