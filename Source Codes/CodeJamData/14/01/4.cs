using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int t = 0; t < T; t++)
			{
				int[] line1 = null;
				int r1 = int.Parse(Console.ReadLine());
				for (int i = 1; i <= 4; i++)
				{
					if (i == r1)
						line1 = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
					else
						Console.ReadLine();
				}

				int[] line2 = null;
				int r2 = int.Parse(Console.ReadLine());
				for (int i = 1; i <= 4; i++)
				{
					if (i == r2)
						line2 = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
					else
						Console.ReadLine();
				}

				int[] intersection = line1.Intersect(line2).ToArray();
				Console.Write("Case #{0}: ", t + 1);
				if (intersection.Length == 0)
					Console.WriteLine("Volunteer cheated!");
				else if (intersection.Length == 1)
					Console.WriteLine(intersection[0]);
				else
					Console.WriteLine("Bad magician!");
			}
		}
	}
}
