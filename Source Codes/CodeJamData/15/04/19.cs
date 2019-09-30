using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemD
{
	class Program
	{
		static void Main(string[] args)
		{
			Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

			var t = int.Parse(Console.ReadLine());
			for (var caseNumber = 1; caseNumber <= t; caseNumber++)
			{
				var line = Console.ReadLine().Split(' ');
				var x = int.Parse(line[0]);
				var r = int.Parse(line[1]);
				var c = int.Parse(line[2]);

				var doesRichardWin = Solve(x, r, c);
				Console.WriteLine("Case #{0}: {1}", caseNumber, doesRichardWin ? "RICHARD" : "GABRIEL");
			}
		}

		static bool Solve(int x, int r, int c)
		{
			if (x >= 7)
				return true;
			if (((r * c) % x) != 0)
				return true;
			if ((r < x) && (c < x))
				return true;
			if ((r < x) || (c < x))
			{
				var min = Math.Min(r, c);
				var max = Math.Max(r, c);
				if (x <= min + 1)
					return false;
				if ((min == 2) && (x >= 5))
					return true;
				return true;
			}
			return false;
		}
	}
}
