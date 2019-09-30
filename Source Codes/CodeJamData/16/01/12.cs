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
                var startingNumber = int.Parse(Console.ReadLine());

                var lastNumber = TryGetLastNumber(startingNumber);

                Console.WriteLine("Case #{0}: {1}", caseNumber, lastNumber?.ToString() ?? "INSOMNIA");
            }
        }

        private static int? TryGetLastNumber(int startingNumber)
        {
            if (startingNumber == 0)
                return null;

            var digitsSeen = new HashSet<char>();
            var allDigits = new HashSet<char>(Enumerable.Range(0, 10).Select(digit => digit.ToString()[0]));

            var multiplier = 1;
            while (true)
            {
                var currentNumber = startingNumber * multiplier;
                digitsSeen.UnionWith(currentNumber.ToString());

                if (digitsSeen.SetEquals(allDigits))
                    return currentNumber;

                multiplier++;
            }
        }
    }
}
