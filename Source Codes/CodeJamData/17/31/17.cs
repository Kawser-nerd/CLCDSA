using System;
using System.Linq;
using GoogleCodeJam.Utilities;

namespace GoogleCodeJam2017.Round1C
{
    public class A
    {
        public static void Main(string[] args)
        {
            var numberOfCases = IO.ReadInt();
            for (var i = 0; i < numberOfCases; i++)
            {
                var result = Calculate();
                IO.WriteDouble(i + 1, result);
            }
        }

        public static double Calculate()
        {
            var input = IO.ReadIntArray();
            var n = input[0];
            var k = input[1];
            var pancakes = IO.ReadIntJagged(n);

            var best = 0d;
            for(var i = 0; i < n; i++)
            {
                var k1 = k;
                var firstPancake = pancakes[i];
                var a = Top(firstPancake) + Side(firstPancake);
                k1--;

                var remainingPancakes = pancakes.Except(new[] { firstPancake })
                    .Where(p => p[0] <= firstPancake[0])
                    .OrderByDescending(Side);
                foreach (var p in remainingPancakes)
                {
                    if (k1 == 0)
                    {
                        break;
                    }

                    a += Side(p);
                    k1--;
                }
                if (k1 == 0)
                {
                    best = Math.Max(best, a);
                }
            }
            return best;
        }

        private static double Top(int[] p) => Math.PI * p[0] * p[0];

        private static double Side(int[] p) => 2 * Math.PI * p[0] * p[1];
    }
}
