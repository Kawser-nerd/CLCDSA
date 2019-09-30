using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
	class Program
	{
		static void Main(string[] a_asArgs)
		{
			int[] l_aiInput = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
			int l_iN = l_aiInput[0];
			int l_iM = l_aiInput[1];

			for (int l_iD = l_iM / l_iN; l_iD >= 1; l_iD--)
			{
				if (l_iM % l_iD == 0)
				{
					Console.WriteLine(l_iD);
					break;
				}
			}
		}
	}
}