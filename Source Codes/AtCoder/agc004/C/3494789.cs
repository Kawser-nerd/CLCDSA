using System;
using System.Linq;

namespace agc004_c
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			bool[,] table = new bool[x[0], x[1]];
			for (int i = 0; i < x[0]; i++)
			{
				string s = Console.ReadLine();
				for (int j = 0; j < x[1]; j++)
				{
					table[i, j] = s[j] == '#';
				}
			}
			for (int i = 0; i < x[0]; i++)
			{
				for (int j = 0; j < x[1]; j++)
				{
					if (table[i, j] || i % 2 == 0 && j != x[1] - 1 || j == 0) Console.Write("#");
					else Console.Write(".");
				}
				Console.WriteLine();
			}
			Console.WriteLine();
			for (int i = 0; i < x[0]; i++)
			{
				for (int j = 0; j < x[1]; j++)
				{
					if (table[i, j] || i % 2 == 1 && j != 0 || j == x[1] - 1) Console.Write("#");
					else Console.Write(".");
				}
				Console.WriteLine();
			}
		}
	}
}