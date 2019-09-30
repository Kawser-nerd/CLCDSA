using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq23_1
{
	class Program
	{
		static void Main(string[] args)
		{
			int x = int.Parse(Console.ReadLine());

			int num10 = x / 10;
			int num = x % 10;

			Console.WriteLine(num10 + num);
		}
	}
}