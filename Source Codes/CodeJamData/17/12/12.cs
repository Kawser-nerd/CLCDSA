using System;
using System.Collections.Generic;
using System.Linq;

namespace RoundOne
{
    internal class ProgramB
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var T = Convert.ToInt32(input);

            var k = 1;
            while (k <= T)
            {
                var answer = ProcessTestCase();

                Console.WriteLine($"Case #{k}: {answer}");
                k++;
            }
        }

        internal static string ProcessTestCase()
        {
            var parameters = Console.ReadLine().Split(' ');
            var N = Convert.ToInt32(parameters[0]);
            var Packs = Convert.ToInt32(parameters[1]);

            var recipe = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            var packets = new int[N][];
            for (int i = 0; i < N; i++)
            {
                packets[i] = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                Array.Sort(packets[i]);
            }

            var listPositions = new int[N];
            var kitCount = 0;

            var targetNumberOfRecipes = 1;
            while (listPositions.All(p => p < Packs))
            {
                //loop through looking for valid packs for the current target kit
                // any that are too small will never be useful again
                // once we run out of useful packets of some ingredient, we're done.
                var kitFound = true;
                for (int i = 0; i < N; i++)
                {
                    var currentPacket = packets[i][listPositions[i]];
                    var amountNecessaryForTarget = recipe[i] * targetNumberOfRecipes;

                    while (listPositions[i] < Packs
                        && BelowThreshold(currentPacket, amountNecessaryForTarget))
                    {
                        listPositions[i]++;
                        if (listPositions[i] < Packs)
                            currentPacket = packets[i][listPositions[i]];
                    }

                    if (BelowThreshold(currentPacket, amountNecessaryForTarget)
                        || AboveThreshold(currentPacket, amountNecessaryForTarget))
                    {
                        kitFound = false;
                        break;
                    }
                }

                if (kitFound)
                {
                    kitCount++;
                    for (int i = 0; i < N; i++)
                    {
                        listPositions[i]++;
                    }
                }
                else
                {
                    targetNumberOfRecipes++;
                }
            }

            return kitCount.ToString();
        }

        private static bool AboveThreshold(int currentPacket, int necessaryForTarget)
        {
            return currentPacket > 1.1 * necessaryForTarget;
        }

        private static bool BelowThreshold(int currentPacket, int necessaryForTarget)
        {
            return currentPacket < 0.9 * necessaryForTarget;
        }
    }
}
