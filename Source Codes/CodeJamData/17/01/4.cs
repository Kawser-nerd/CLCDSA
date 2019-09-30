using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PanCakeFlipper
{
    class PanCakeFlipper
    {
        static void Main(string[] args)
        {
            int numberOfSamples = int.Parse(Console.ReadLine());

            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample              
                string[] values = Console.ReadLine().Split(' ');
                int toolSize = int.Parse(values[1]);
                char[] cakes = values[0].ToCharArray();
                SolveTheProblem(sp + 1, cakes, toolSize);
            }
        }

        static char Flip(char c)
        {
            if (c == '+')
                return '-';

            return '+';
        }

        static void FlipRange(char[] cakes, int from, int size)
        {
            for (int i = 0; i < size; i++)
            {
                cakes[from + i] = Flip(cakes[from + i]);
            }
        }

        static int NumberOfFlip(char[] cakes, int startIndex, int toolSize)
        {
            int lastWrong = Array.IndexOf(cakes, '-', startIndex);

            if (lastWrong == -1) // no need to flip
                return 0;

            if (cakes.Length - lastWrong < toolSize)
            {
                return -1;
            }

            FlipRange(cakes, lastWrong, toolSize);

            int nextFlips = NumberOfFlip(cakes, lastWrong + 1, toolSize);
            if (nextFlips < 0)
            {
                return nextFlips;
            }

            return nextFlips + 1;
        }

        static void SolveTheProblem(int sp, char[] cakes, int toolSize)
        {
            int outValue;

            // Calculation
            outValue = NumberOfFlip(cakes, 0, toolSize);

            // Print results
            Console.Write("Case #{0}: ", sp);
            if (outValue == -1)
            {
                Console.Write("IMPOSSIBLE");
            }
            else
            {
                Console.Write(outValue);
            }
            Console.WriteLine();
        }
    }
}
