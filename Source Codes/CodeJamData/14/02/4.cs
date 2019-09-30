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
			for (int t = 1; t <= T; t++)
			{
				string[] parts = Console.ReadLine().Split();
				decimal C = decimal.Parse(parts[0]);
				decimal F = decimal.Parse(parts[1]);
				decimal X = decimal.Parse(parts[2]);

				int p = (int)Math.Ceiling(C / X);
				decimal min = X / 2;
				decimal acc = 0;
				for (int i = 2; ; i++)
				{
					acc += C / (2 + (i - 2) * F);
					decimal newVal = acc + X / (2 + F * (i - 1));
					if (min > newVal)
						min = newVal;

					if (acc > min)
						break;
				}

				Console.WriteLine("Case #{0}: {1}", t, min);
			}
		}
	}
}
