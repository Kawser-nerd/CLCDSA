using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
	public class Program
	{
		// ABC103-C
		static void Main(string[] args)
		{
			int N = int.Parse(Console.ReadLine());
			long sum = 0;
			foreach (var s in Console.ReadLine().Split()) {
				sum += long.Parse(s) - 1;
			}
			Console.WriteLine(sum);
		}
	}
}