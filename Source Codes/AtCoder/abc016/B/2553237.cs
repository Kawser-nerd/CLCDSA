using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq16_02
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] split = Console.ReadLine().Split(' ');
			int a = int.Parse(split[0]);
			int b = int.Parse(split[1]);
			int result = int.Parse(split[2]);

			int add = a + b;
			int sub;
			if(a < b)
			{
				sub = b - a;
			}
			else
			{
				sub = a - b;
			}

			if(add == result && sub == result)
			{
				Console.WriteLine("?");
			}
			else if(add == result)
			{
				Console.WriteLine("+");
			}
			else if (sub == result)
			{
				Console.WriteLine("-");
			}
			else
			{
				Console.WriteLine("!");
			}
		}
	}
}