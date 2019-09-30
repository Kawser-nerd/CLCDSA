using System;
using System.Linq;
using System.Text.RegularExpressions;

namespace algorithm
{
	class Program
	{
		static void Main(string[] args)
		{
			string s = Console.ReadLine();

			int z = s.Where(x => x == '0').Count();
			int i = s.Where(x => x == '1').Count();
			if (z < i)
			{
				
			}
			else
			{
				z = i;
			}
			Console.WriteLine(z*2);
		}
	}
}