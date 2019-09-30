using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleJam
{  
    public class GoogleHelper
    {
        public static int GetMaxWithoutSurprise(int scores)
        {
            return (scores + 2)/3;
        }

        public static bool IncrementFromSurprise(int scores)
        {
            return scores%3 != 1 && scores > 0 && scores < 28;
        }

        public static int CalcMaxGooglers(int[] scores, int surprises, int leastWantedMax)
        {
            int achievedMax = 0;
            int surpriseBonusable = 0;
            foreach (var score in scores)
            {
                int max = GetMaxWithoutSurprise(score);
                if (max >= leastWantedMax)
                    achievedMax++;
                if (max == leastWantedMax - 1 && IncrementFromSurprise(score))
                    surpriseBonusable++;
            }
            return achievedMax + Math.Min(surpriseBonusable, surprises);
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            var tr = new StreamReader(@"C:\GJ\input.in");
            using (var tw = new StreamWriter(@"C:\GJ\output.out"))
            {
                int testCount = int.Parse(tr.ReadLine());
                for (int i = 0; i < testCount; i++)
                {
                    var line = tr.ReadLine();
                    var ints = line.Split().Select(int.Parse).ToArray();
                    var maxGooglers = GoogleHelper.CalcMaxGooglers(ints.Skip(3).ToArray(), ints[1], ints[2]);
                    tw.WriteLine(string.Format("Case #{0}: {1}", i+1, maxGooglers));
                }
            }
        }
    }
}
