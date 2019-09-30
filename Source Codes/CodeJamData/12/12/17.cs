using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Kingdom
{
    class Kingdom
    {
        static void Main(string[] args)
        {
            int testCases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= testCases; i++)
                new Kingdom().Solve(i);
        }

        void Solve(int testCase)
        {
            var numLevels = int.Parse(Console.ReadLine());
            var levels = Enumerable.Range(0, numLevels).Select(i => new Level(Console.ReadLine().Split(' ').Select(int.Parse).ToArray()))
                .OrderByDescending(lv => lv.ExpertRequiredStars).ToArray();

            var stars = 0;
            var turns = 0;
            while (stars < levels.Length * 2)
            {
                turns++;
                Level choice;
                if ((choice = levels.FirstOrDefault(lv => !lv.CompletedOnNormal && !lv.CompletedOnExpert && stars >= lv.ExpertRequiredStars)) != null)
                {
                    choice.CompletedOnNormal = choice.CompletedOnExpert = true;
                    stars += 2;
                }
                else if ((choice = levels.FirstOrDefault(lv => lv.CompletedOnNormal && !lv.CompletedOnExpert && stars >= lv.ExpertRequiredStars)) != null)
                {
                    choice.CompletedOnExpert = true;
                    stars++;
                }
                else if ((choice = levels.FirstOrDefault(lv => !lv.CompletedOnNormal && !lv.CompletedOnExpert && stars >= lv.NormalRequiredStars)) != null)
                {
                    choice.CompletedOnNormal = true;
                    stars++;
                }
                else
                {
                    turns = -1; // Got stuck
                    break;
                }
            }

            Console.WriteLine("Case #{0}: {1}", testCase, turns >= 0 ? turns.ToString() : "Too Bad");
        }
    }

    class Level
    {
        public bool CompletedOnNormal;
        public bool CompletedOnExpert;
        public int NormalRequiredStars;
        public int ExpertRequiredStars;

        public Level(int[] a)
        {
            NormalRequiredStars = a[0];
            ExpertRequiredStars = a[1];
        }
    }
}
