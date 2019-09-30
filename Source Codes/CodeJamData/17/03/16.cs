using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace stalls
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader("C-large.in"));
            //Console.SetOut(new StreamWriter("large.out"));
            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                long[] tokens = Array.ConvertAll(Console.ReadLine().Split(' ').ToArray(), long.Parse);
                long n = tokens[0];
                long k = tokens[1];
                long max, min;
                Solve(n, k, out max, out min);
                Console.WriteLine("Case #{0}: {1} {2}", (i+1), max, min);
            }
            //Console.Out.Flush();
        }

        private static void Solve(long n, long k, out long max, out long min)
        {
            max = 0;
            min = 0;
            
            Dictionary<long, long> sequence = GetSequence(n);
            long c = 0;
            long last = 0;
            do
            {
                long gap = sequence.First().Key;
                c += sequence.First().Value;
                last = gap;
                sequence.Remove(gap);
            } while (c < k);

            long[] m = GetSubgaps(last);
            if (m.Length > 1)
            {
                max = m.Max();
                min = m.Min();
            }
            else if (m.Length == 1)
            {
                max = m[0];                
            }
        }

        private static Dictionary<long, long> GetSequence(long n)
        {
            Dictionary<long, long> sequence = new Dictionary<long, long>();
            Dictionary<long, long> occurs = new Dictionary<long, long>();
            occurs.Add(n, 1);
            while (occurs.Count > 0)
            {
                long gapsize = occurs.OrderByDescending(x => x.Key).First().Key;
                long count = occurs.OrderByDescending(x => x.Key).First().Value;
                sequence.Add(gapsize, count);
                occurs.Remove(gapsize);
                if (gapsize == 1)
                    break;
                long[] subgaps = GetSubgaps(gapsize);
                foreach (long newgap in subgaps.OrderByDescending(x => x))
                {
                    if (!occurs.ContainsKey(newgap))
                    {
                        occurs.Add(newgap, 0);
                    }
                    occurs[newgap] = occurs[newgap] + count;
                }
            }
            return sequence;
        }

        private static long[] GetSubgaps(long gapsize)
        {
            if (gapsize == 1)
                return new long[] {};
            if (gapsize == 2)
                return new long[] {1};
            if (gapsize % 2 == 0)
                return new long[] { gapsize / 2, gapsize / 2 - 1 };
            else
                return new long[] { gapsize / 2, gapsize / 2 };
        }
    }
}

