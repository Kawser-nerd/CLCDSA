using System;

namespace B
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var o = Console.ReadLine();
			var e = Console.ReadLine();

			for (var i = 0; i < e.Length; i++)
			{
				Console.Write(o[i]);
				Console.Write(e[i]);
			}

			if (o.Length > e.Length) { Console.WriteLine(o.Substring(o.Length - 1)); }
		}
	}
}