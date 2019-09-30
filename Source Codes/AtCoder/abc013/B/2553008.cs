using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cip13_02
{
	class Program
	{
		static void Main(string[] args)
		{
			int a = int.Parse(Console.ReadLine());
			int b = int.Parse(Console.ReadLine());

			int aa = a + 10;
			int bb = b + 20;

			int[] check = new int[3];

			check[0] = aa - b;
			check[1] = bb - aa;
			check[2] = a - b;
			
			if(check[2] < 0)
			{
				check[2] = check[2] * -1;
			}
			int min = 10;
			for(int i = 0;i < 3; i++)
			{
				if(min > check[i])
				{
					min = check[i];
				}
			}
			Console.WriteLine(min);
		}
	}
}