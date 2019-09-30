using System;

namespace ABC065_A_Expired
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string[] input = Console.ReadLine().Split(' ');
			int x = int.Parse(input[0]);
			int a = int.Parse(input[1]);
			int b = int.Parse(input[2]);

			int eatDay = b - a;
			if(x < eatDay) Console.WriteLine("dangerous");
			else if(eatDay > 0) Console.WriteLine("safe");
			else Console.WriteLine("delicious");
		}
	}
}