using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpTest
{
	class Program
	{
		static void Main(string[] args)
		{
			var line1 = Console.ReadLine().Split(' ');
			var line2 = Console.ReadLine().Split(' ');

			var N = int.Parse(line1[0]);
			var K = int.Parse(line1[1]);
			var c = new Dictionary<int, int>();
			foreach(var l in line2)
			{
				c[int.Parse(l)] = c.ContainsKey(int.Parse(l)) ? c[int.Parse(l)] + 1 : 1;
			}

			//?????????????
			var sorted = c.OrderBy(a => a.Value).Take(Math.Max(0, c.Count - K));
			var ret = 0;
			foreach(var s in sorted)
				ret += s.Value;
			Console.WriteLine(ret);
		}
	}
}