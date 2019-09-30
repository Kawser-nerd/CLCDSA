using System;

namespace B
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var s = Console.ReadLine().ToCharArray();
			var t = Console.ReadLine().ToCharArray();
			Array.Sort(s);
			Array.Sort(t);
			Array.Reverse(t);
			Console.WriteLine(string.Compare(new string(s), new string(t)) >= 0 ? "No" : "Yes");
		}
	}
}