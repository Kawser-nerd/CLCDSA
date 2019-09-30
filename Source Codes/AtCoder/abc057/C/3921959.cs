using System;

namespace ABC057_C_Digits_in_Multiplication
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			long n = long.Parse(Console.ReadLine());
			long a;
			long b;

			int resultLength = n.ToString().Length;
			for (long i = 1; i <= Math.Sqrt(n); i++)
			{
				if (n % i == 0)
				{
					a = i;
					b = n / i;
					int length;
					if (a.ToString().Length <= b.ToString().Length)
						length = b.ToString().Length;
					else
						length = a.ToString().Length;

					if (resultLength > length)
						resultLength = length;
				}
			}
			
			Console.WriteLine(resultLength);
		}
	}
}