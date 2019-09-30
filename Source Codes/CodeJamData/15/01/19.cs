using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
			var t = int.Parse(Console.ReadLine());
			for (var caseNumber = 1; caseNumber <= t; caseNumber++)
			{
				var line = Console.ReadLine();
				var lineItems = line.Split(' ');
				var sMax = int.Parse(lineItems[0]);
				var sValues = lineItems[1].Select(digit => int.Parse(new string(digit, 1))).ToList();
				var requiredGuestCount = 0;
				var currentStanding = 0;
				for (var currentShines = 0; currentShines <= sMax; currentShines++)
				{
					if (currentStanding < currentShines)
					{
						requiredGuestCount++;
						currentStanding++;
					}
					currentStanding += sValues[currentShines];
				}
				Console.WriteLine("Case #{0}: {1}", caseNumber, requiredGuestCount);
			}
		}
	}
}
