using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.AGC011
{
    static class Colorful_Creatures
    {
        public static void Main()
        {
            var n = long.Parse(ReadLine().Trim());
            var creatures = ReadLine().Trim().Split(' ').Select(i => long.Parse(i)).OrderBy(i => i).ToArray();
            WriteLine(solve(creatures));
        }
        static long solve(long[] creatures)
        {
            var sumCreatures = new long[creatures.Length];
            for (var i = 1; i < sumCreatures.Length; ++i)
                sumCreatures[i] = sumCreatures[i - 1] + creatures[i - 1];
            for (var i = 1; i <= creatures.Length; ++i)
            {
                if (creatures[creatures.Length - i]  > 2 * sumCreatures[sumCreatures.Length - i]) return i;
            }
            return creatures.Length;
        }
    }
}