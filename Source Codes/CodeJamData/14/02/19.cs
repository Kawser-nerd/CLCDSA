using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfTestCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, Trial());
            }
        }

        static string Trial()
        {
            var testCase = Console.ReadLine().Split(' ').Select((x) => (double.Parse(x)));
            double farmPrice = testCase.ElementAt(0);
            double farmGain = testCase.ElementAt(1);
            double target = testCase.ElementAt(2);

            double prevTotalTimeToAchieve = double.PositiveInfinity;
            double totalTimeToBuy = 0.0;

            for (int i = 0; ; i++)
            {
                double gain = farmGain * i + 2.0;
                double totalTimeToAchieve = target / gain + totalTimeToBuy;

                if (prevTotalTimeToAchieve < totalTimeToAchieve)
                {
                    break;
                }

                totalTimeToBuy += farmPrice / gain;
                prevTotalTimeToAchieve = totalTimeToAchieve;
            }

            return prevTotalTimeToAchieve.ToString("F7");
        }
    }
}
