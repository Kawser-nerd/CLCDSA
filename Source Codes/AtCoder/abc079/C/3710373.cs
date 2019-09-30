using System;

namespace ABC079_C_Train_Ticket
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string input = Console.ReadLine();
			int a = int.Parse(input.Substring(0, 1));
			int b = int.Parse(input.Substring(1, 1));
			int c = int.Parse(input.Substring(2, 1));
			int d = int.Parse(input.Substring(3, 1));

			if (b + c + d == 7 - a)
			{
				Console.WriteLine(a + "+" + b + "+" + c + "+" + d + "=" + 7);
			}else if (- b + c + d == 7 - a)
			{
				Console.WriteLine(a + "-" + b + "+" + c + "+" + d + "=" + 7);
			}else if (- b - c + d == 7 - a)
			{
				Console.WriteLine(a + "-" + b + "-" + c + "+" + d + "=" + 7);
			}else if (- b - c - d == 7 - a)
			{
				Console.WriteLine(a + "-" + b + "-" + c + "-" + d + "=" + 7);
			}else if (- b + c - d == 7 - a)
			{
				Console.WriteLine(a + "-" + b + "+" + c + "-" + d + "=" + 7);
			}else if (b - c + d == 7 - a)
			{
				Console.WriteLine(a + "+" + b + "-" + c + "+" + d + "=" + 7);
			}else if (b - c - d == 7 - a)
			{
				Console.WriteLine(a + "+" + b + "-" + c + "-" + d + "=" + 7);
			}else if (b + c - d == 7 - a)
			{
				Console.WriteLine(a + "+" + b + "+" + c + "-" + d + "=" + 7);
			}
		}
	}
}