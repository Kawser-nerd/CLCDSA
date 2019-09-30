using System;
using System.Collections.Generic;

namespace AtCoder
{
	public class Program
	{
		// ABC108-B
		static void Main(string[] args)
		{
			string[] vs = Console.ReadLine().Split();
			int x1 = int.Parse(vs[0]);
			int y1 = int.Parse(vs[1]);
			int x2 = int.Parse(vs[2]);
			int y2 = int.Parse(vs[3]);
			int x3, x4, y3, y4;
			int dx = x2 - x1;
			int dy = y2 - y1;
			x3 = x2 - dy;
			y3 = y2 + dx;
			x4 = x3 - dx;
			y4 = y3 - dy;
			Console.WriteLine(string.Format("{0} {1} {2} {3}", x3, y3, x4, y4));
		}
	}
}