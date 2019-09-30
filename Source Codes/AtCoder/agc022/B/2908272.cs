using System;

namespace agc022_b
{
	class Program
	{
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			if (n == 3) Console.WriteLine("2 5 63");
			else
			{
				int[] x = new int[] { 2, 3, 4, 6, 8, 9, 10, 12 };
				bool first = true;
				for (int i = 0; i < n / 8; i++)
				{
					foreach (int a in x)
					{
						if (first) first = false;
						else Console.Write(" ");
						Console.Write(i * 12 + a);
					}
				}
				int end = n / 8 * 12;
				if (first) first = false;
				else Console.Write(" ");
				switch (n % 8)
				{
					case (0): break;
					case (1):
					{
						Console.Write((end + 6));
						break;
					}
					case (2):
					{
						Console.Write((end + 2) + " " + (end + 4));
						break;
					}
					case (3):
					{
						Console.Write((end + 4) + " " + (end + 6) + " " + (end + 8));
						break;
					}
					case (4):
					{
						Console.Write((end + 2) + " " + (end + 3) + " " + (end + 4) + " " + (end + 9));
						break;
					}
					case (5):
					{
						Console.Write((end + 2) + " " + (end + 3) + " " + (end + 6) + " " + (end + 9) + " " + (end + 10));
						break;
					}
					case (6):
					{
						Console.Write((end + 2) + " " + (end + 3) + " " + (end + 6) + " " + (end + 9) + " " + (end + 10) + " " + (end + 12));
						break;
					}
					case (7):
					{
						Console.Write((end + 2) + " " + (end + 3) + " " + (end + 4) + " " + (end + 6) + " " + (end + 8) + " " + (end + 9) + " " + (end + 10));
						break;
					}
				}
			}
		}
	}
}