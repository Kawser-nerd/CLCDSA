using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq12_02
{
	class Program
	{
		static void Main(string[] args)
		{
			int t = int.Parse(Console.ReadLine());

			int h, m, s, ms;

			ms = t / 60;
			s = t % 60;
			h = ms / 60;
			m = ms % 60;

			Console.WriteLine("{0:D2}:{1:D2}:{2:D2}",h,m,s);
		}
	}
}