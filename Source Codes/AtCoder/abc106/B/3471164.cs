using System;

namespace ABC106_B_105
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			int yakusuu = 0;
			int value = 0;

			for (int i = 1; i <= n; i += 2)
			{
				yakusuu = 0;
				for (int j = 1; j <= i; j++) {
					if (i % j == 0)
					{
						yakusuu++;
					}
				}

				if (yakusuu == 8)
				{
					value++;
				}
			}
			
			Console.Write(value);
		}
	}
}