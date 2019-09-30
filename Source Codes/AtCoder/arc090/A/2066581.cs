using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] a_asArgs)
        {
			Console.ReadLine();
			int[] l_aiInput1 = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
			int[] l_aiInput2 = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

			int l_iSum1 = l_aiInput1.Sum();
			int l_iSum2 = l_aiInput2.Sum();

			int l_iGetMax = 0;
			for (int l_iIndex = 0; l_iIndex < l_aiInput1.Length; l_iIndex++)
			{
				int l_iGet = l_aiInput1.Where((a, i) => i <= l_iIndex).Sum() + l_aiInput2.Where((a, i) => i >= l_iIndex).Sum();
				l_iGetMax = l_iGetMax > l_iGet ? l_iGetMax : l_iGet;
			}
			Console.WriteLine(l_iGetMax);
		}
	}
}