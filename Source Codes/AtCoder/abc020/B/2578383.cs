using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq20_02
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] split = Console.ReadLine().Split(' ');
			string stringadd = split[0] + split[1];

			int add = int.Parse(stringadd);

			Console.WriteLine(add * 2);
		}
	}
}