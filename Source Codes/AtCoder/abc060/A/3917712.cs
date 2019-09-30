using System;

namespace ABC060_A_Shiritori
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			string a = input[0];
			string b = input[1];
			string c = input[2];

			if (a.Substring(a.Length - 1, 1) == b.Substring(0, 1))
			{
				if (b.Substring(b.Length - 1, 1) == c.Substring(0, 1))
				{
					Console.WriteLine("YES");
					return;
				}	
			}
			Console.WriteLine("NO");
		}
	}
}