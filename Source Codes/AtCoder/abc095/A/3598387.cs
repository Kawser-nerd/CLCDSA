using System;

namespace ABC095_A_Something_on_It
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string s = Console.ReadLine();

			int count = 0;
			
			for (int i = 0; i < 3; i++) {
				if (s.Substring(i, 1) == "o")
				{
					count++;
				}
			}
			
			Console.WriteLine(700 + count * 100);
		}
	}
}