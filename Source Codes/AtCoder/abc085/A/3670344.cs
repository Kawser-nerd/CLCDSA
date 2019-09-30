using System;

namespace ABC085_A_Already_2018
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string s = Console.ReadLine();
			string sSubStr = s.Substring(4, 6);
			Console.WriteLine("2018" + sSubStr);
		}
	}
}