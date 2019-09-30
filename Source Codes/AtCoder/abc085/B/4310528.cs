using System;
using System.Collections.Generic;
using System.Linq;

namespace B1
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var n = int.Parse(Console.ReadLine());
			var dn = new List<int>(n);
			for (var i = 0; i < n; i++) { dn.Add(int.Parse(Console.ReadLine())); }

			Console.WriteLine(dn.Distinct().Count());
		}
	}
}