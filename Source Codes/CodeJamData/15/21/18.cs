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
                var target = Console.ReadLine();
                var result = CountTo(long.Parse(target));
                Console.WriteLine("Case #{0}: {1}", caseNumber, result);
            }
        }

        static long CountTo(long target)
        {
            var targetString = target.ToString();
            if (targetString.Length == 1)
                return target;

            var firstEndDigitCount = (targetString.Length + 1) / 2;
            var reverseEndDigitCount = targetString.Length - firstEndDigitCount;

            var firstEndNumber = long.Parse(targetString.Substring(reverseEndDigitCount));
            var reverseNumberString = new string(targetString.Reverse().ToArray());
            var reverseEndNumberString = reverseNumberString.Substring(firstEndDigitCount);
            var reverseEndNumber = long.Parse(reverseEndNumberString);

            if (reverseEndNumber == 1)
                return CountTo(target - firstEndNumber - 1) + firstEndNumber + 1;

            if (firstEndNumber == 0)
                return CountTo(target - 1) + 1;

            var intermediate = target - firstEndNumber + 1;
            var reverseIntermediate = long.Parse(new string(intermediate.ToString().Reverse().ToArray()));
            return CountTo(reverseIntermediate) + firstEndNumber;
        }
    }
}
