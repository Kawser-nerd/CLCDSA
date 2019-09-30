using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class WelcomeToCodeJam
    {
        public static void Main()
        {
            int N = int.Parse(Console.ReadLine());

            for (int i = 0; i < N; i++)
                Console.WriteLine("Case #{0}: {1:0000}", i+1, Solve(Console.ReadLine()));
        }

        static int?[,] cache;
        static String pattern = "welcome to code jam";
        static String phrase;

        private static int Solve(string p)
        {
            phrase = p;
            cache = new int?[pattern.Length+1, p.Length+1];
            return findSolution(0, 0);
        }

        private static int findSolution(int patternEaten, int phraseEaten)
        {
            int? result = cache[patternEaten, phraseEaten];
            if (!result.HasValue)
                result = cache[patternEaten, phraseEaten] = solve(patternEaten, phraseEaten);
            return result.Value;
        }

        private static int solve(int patternEaten, int phraseEaten)
        {
            if (patternEaten == pattern.Length)
                return 1;
            if (phraseEaten == phrase.Length)
                return 0;

            int result = 0;
            if (pattern[patternEaten] == phrase[phraseEaten])
                result += findSolution(patternEaten + 1, phraseEaten + 1);
            result += findSolution(patternEaten, phraseEaten + 1);

            return result % 10000;
        }
    }
}
