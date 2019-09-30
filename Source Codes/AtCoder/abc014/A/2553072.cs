using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq14_01
{
	class Program
	{
		static void Main(string[] args)
		{
			int a = int.Parse(Console.ReadLine());
			int b = int.Parse(Console.ReadLine());

			int kaitasi;

			if (a % b > 0)
			{
				kaitasi = b - (a % b);
			}
			else
			{
				kaitasi = 0;
			}
			Console.WriteLine(kaitasi);
		}
	}
}