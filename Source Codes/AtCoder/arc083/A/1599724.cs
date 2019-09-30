using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder
{
	class Program
	{
		static void Main(string[] args)
		{
			var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

			double nodo = 0;
			int[] ans = new int[2];
			for (int i = 0; i <= input[5] / (100 * input[0]); i++)
			{
				for (int j = 0; j <= input[5] / (100 * input[1]); j++)
				{
					int water = 100 * input[0] * i + 100 * input[1] * j;
					if (water > input[5]) continue;
					int s_max = (input[4] * water) / 100;
					for (int k = 0; k <= s_max / input[2]; k++)
					{
						for (int l = 0; l <= (s_max - k * input[2]) / input[3]; l++)
						{
							int sato = input[2] * k + input[3] * l;
							if (water + sato > input[5]) continue;
							if (100 * sato > input[4] * water) continue;
							if (nodo <= (double)sato / (water + sato))
							{
								nodo = (double)sato / (water + sato);
								ans[0] = water + sato;
								ans[1] = sato;
							}
						}
					}
				}
			}
			Console.WriteLine(ans[0] + " " + ans[1]);
			//Console.ReadLine();
		}
	}
}