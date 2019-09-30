using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamR1A2012
{
    class Program
    {
        static private void R1A_A()
        {
            int numTestCases = Int32.Parse(Console.ReadLine());
            for (int zz = 0; zz < numTestCases; zz++)
            {
                string aAndBText = Console.ReadLine();
                string[] splits = aAndBText.Split(' ');
                int numCharsTyped = Int32.Parse(splits[0]);
                int totalPwCharCount = Int32.Parse(splits[1]);

                string chancesText = Console.ReadLine();
                splits = chancesText.Split(' ');
                List<double> ps = new List<double>(splits.Select(s => Double.Parse(s)));

                double chanceAllAreCorrect = 1.0;
                for (int q = 0; q < numCharsTyped; ++q)
                {
                    chanceAllAreCorrect *= ps[q];
                }

                double costForKeepTyping =
                    ((1 + totalPwCharCount - numCharsTyped) * chanceAllAreCorrect)
                    + (1 + totalPwCharCount + 1 + totalPwCharCount - numCharsTyped) * (1.0 - chanceAllAreCorrect);

                double costForPressEnter =
                    (numCharsTyped == totalPwCharCount)
                    ? ((chanceAllAreCorrect * 1) + ((1.0 - chanceAllAreCorrect) * (2 + totalPwCharCount)))
                    : (2 + totalPwCharCount);

                double optimalKeyStrokes = Math.Min(costForKeepTyping, costForPressEnter);

                for (int numBackspaces = 1; numBackspaces <= numCharsTyped; ++numBackspaces)
                {
                    double chancesLeftoversAreCorrect = 1.0;
                    int leftoverCount = numCharsTyped - numBackspaces;
                    for (int leftoverIndex = 0; leftoverIndex < leftoverCount; leftoverIndex++)
                    {
                        chancesLeftoversAreCorrect *= ps[leftoverIndex];
                    }

                    double keystrokes = numBackspaces
                        + chancesLeftoversAreCorrect * (1 + totalPwCharCount - leftoverCount)
                        + (1.0 - chancesLeftoversAreCorrect)*(2 + totalPwCharCount + totalPwCharCount - leftoverCount);

                    optimalKeyStrokes = Math.Min(keystrokes, optimalKeyStrokes);
                }

                Console.WriteLine(String.Format("Case #{0}: {1}", zz + 1, optimalKeyStrokes));
            }
        }

        static void Main(string[] args)
        {
            R1A_A();
        }
    }
}
