using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq12_3
{
	class Program
	{
		static void Main(string[] args)
		{
			int num = int.Parse(Console.ReadLine());
			int loss = 2025 - num;

			int[,] kuku = new int[9, 9];

			for(int i = 0;i <= 8; i++)
			{
				for(int j = 0;j <= 8; j++)
				{
					kuku[i, j] = (i + 1) * (j + 1);
				}
			}
			for (int i = 0; i <= 8; i++)
			{
				for (int j = 0; j <= 8; j++)
				{
					if(kuku[i,j] == loss)
					{
						Console.WriteLine("{0} x {1}", i + 1, j + 1);
					}
				}
			}
		}
	}
}