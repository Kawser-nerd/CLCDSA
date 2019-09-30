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

            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
	            var numbers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
	            var rowCount = numbers[0];
	            var columnCount = numbers[1];
	            var shipWidth = numbers[2];

	            var toFirstHit = rowCount * (columnCount / shipWidth);
	            var toDirection = (columnCount == shipWidth) || (shipWidth == 1) || (columnCount % shipWidth == 0) ? 0 : 1;
	            var toKill = shipWidth - 1;
	            var result = toFirstHit + toDirection + toKill;

				Console.WriteLine("Case #{0}: {1}", caseNumber, result);
            }
        }
    }
}
