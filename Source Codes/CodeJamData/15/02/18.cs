using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemB
{
	class Program
	{
		static void Main(string[] args)
		{
			Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

			var t = int.Parse(Console.ReadLine());
			for (var caseNumber = 1; caseNumber <= t; caseNumber++)
			{
				var d = int.Parse(Console.ReadLine());
				var pValues = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
				var bestTime = Solve(pValues);
				Console.WriteLine("Case #{0}: {1}", caseNumber, bestTime);
			}
		}

		static int Solve(List<int> pValues)
		{
			for (var time = 1; time <= pValues.Max(); time++)
			{
				for (var specialMinuteCount = 0; specialMinuteCount < time; specialMinuteCount++)
				{
					if (CanFinish(pValues, time, specialMinuteCount))
						return time;
				}
			}

			throw new InvalidOperationException("BUG");
		}

		static bool CanFinish(List<int> pValues, int time, int specialMinuteCount)
		{
			if (time >= pValues.Max() + specialMinuteCount)
				return true;

			return pValues.Sum(p => (p - 1) / (time - specialMinuteCount)) <= specialMinuteCount;
		}
	}
}
