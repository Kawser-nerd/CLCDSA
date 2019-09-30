using System;
using System.Globalization;
using System.Threading;

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
                var pancakes = Console.ReadLine();

                var maneuverCount = GetRequiredManeuverCount(pancakes);

                Console.WriteLine("Case #{0}: {1}", caseNumber, maneuverCount);
            }
        }

        private static int GetRequiredManeuverCount(string pancakes)
        {
            var maneuverCount = 0;
            var nextPancake = '+';
            for (var pancakeIndex = pancakes.Length - 1; pancakeIndex >= 0; pancakeIndex--)
            {
                var pancake = pancakes[pancakeIndex];
                if (pancake != nextPancake)
                {
                    maneuverCount++;
                    nextPancake = pancake;
                }
            }

            return maneuverCount;
        }
    }
}
