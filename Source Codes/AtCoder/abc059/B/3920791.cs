using System;

namespace ABC059_B_Comparison
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string a = Console.ReadLine();
			string b = Console.ReadLine();

			if (a.Length > b.Length)
			{
				Console.WriteLine("GREATER");
				return;
			}
			else if(a.Length < b.Length)
			{
				Console.WriteLine("LESS");
				return;
			}

			for (int i = 0; i < a.Length; i++)
			{
				int aNumOne = int.Parse(a.Substring(i, 1));
				int bNumOne = int.Parse(b.Substring(i, 1));

				if (aNumOne > bNumOne)
				{
					Console.WriteLine("GREATER");
					return;
				}else if (aNumOne < bNumOne)
				{
					Console.WriteLine("LESS");
					return;
				}
			}
			
			Console.WriteLine("EQUAL");
		}
	}
}