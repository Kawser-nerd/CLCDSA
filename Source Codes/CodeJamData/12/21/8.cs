using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using GCJ_base;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main()
        {
            new Gcj1BA().Run();
        }
    }

    class Gcj1BA : Gcj
    {
        public Gcj1BA()
        {
            Problem = 'A';
            Small = false;
        }

        protected override string ComputeCase(TextReader reader)
        {
            var line = reader.ReadLine().Split(' ');
            var contestants = line.Skip(1).Select(int.Parse).ToArray();
            int sum = contestants.Sum();

            var losers = contestants;
            int losersSum = sum;

            double target;
            while (true)
            {
                target = (1.0 + ((double)losersSum / sum)) / losers.Length;

                var newLosers = losers.Where(l => ((double)l / sum) <= target).ToArray();

                if (newLosers.Length == losers.Length)
                    break;

                losers = newLosers;
                losersSum = newLosers.Sum();
            }

            var results = new List<double>();

            target = (1.0 + ((double)losersSum / sum)) / losers.Length;

            foreach (var point in contestants)
            {
                double hasFraction = (double)point / sum;
                double needsFraction = target - hasFraction;
                results.Add(Math.Max(needsFraction * 100, 0));
            }

            return string.Join(" ", results);
        }
    }
}