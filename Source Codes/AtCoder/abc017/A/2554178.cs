using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ciq17_01
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] a = Console.ReadLine().Split(' ');
			string[] b = Console.ReadLine().Split(' ');
			string[] c = Console.ReadLine().Split(' ');

			int[] aa = new int[2];
			int[] bb = new int[2];
			int[] cc = new int[2];

			for(int i = 0;i <= 1; i++)
			{
				aa[i] = int.Parse(a[i]);
				bb[i] = int.Parse(b[i]);
				cc[i] = int.Parse(c[i]);
			}
			Console.WriteLine((aa[0] * aa[1] * 0.1) + (bb[0] * bb[1] * 0.1) + (cc[0] * cc[1] * 0.1));
		}
	}
}