using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemD
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfTestCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                Trial();
            }
        }

        static void Trial()
        {
            int length = int.Parse(Console.ReadLine());
            var naomiBlocks = Console.ReadLine().Split(' ').Select((x) => (double.Parse(x))).ToList();
            var kenBlocks = Console.ReadLine().Split(' ').Select((x) => (double.Parse(x))).ToList();

            naomiBlocks.Sort();
            kenBlocks.Sort();

            int deceitfulWar = DeceitfulWar(ShallowCopy(naomiBlocks), ShallowCopy(kenBlocks));
            int war = War(naomiBlocks, kenBlocks);

            Console.WriteLine("{0} {1}", deceitfulWar, war);
        }

        static int DeceitfulWar(List<double> naomiBlocks, List<double> kenBlocks)
        {
            int score = 0;

            for (int i = 0; i < naomiBlocks.Count; i++)
            {
                double chosenNaomi = naomiBlocks[i];
                if (chosenNaomi < kenBlocks.First())
                {
                    kenBlocks.RemoveAt(kenBlocks.Count - 1);
                }
                else
                {
                    kenBlocks.RemoveAt(0);
                    score++;
                }
            }

            return score;
        }

        static int War(List<double> naomiBlocks, List<double> kenBlocks)
        {
            int score = naomiBlocks.Count;

            for (int i = 0; i < naomiBlocks.Count; i++)
            {
                double chosenNaomi = naomiBlocks[i];

                int chosenKenIndex = kenBlocks.FindIndex((x) => (chosenNaomi < x));
                if (chosenKenIndex < 0)
                {
                    break;
                }
                kenBlocks.RemoveAt(chosenKenIndex);
                score--;
            }

            return score;
        }

        static List<double> ShallowCopy(List<double> source)
        {
            return new List<double>(source);
        }
    }
}
