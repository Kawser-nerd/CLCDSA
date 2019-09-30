using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq12_01
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] split = Console.ReadLine().Split(' ');
			int a = int.Parse(split[0]);
			int b = int.Parse(split[1]);

			int swap;

			swap = a;
			a = b;
			b = swap;

			Console.WriteLine("{0} {1}", a, b);
		}
	}
}