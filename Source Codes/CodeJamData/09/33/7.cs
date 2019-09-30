using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1._3
{
    class Program
    {
        public struct Index
        {
            public int start;
            public int length;

            public override bool Equals(object obj)
            {
                var other = (Index)obj;
                return start == other.start && length == other.length;
            }

            public override int GetHashCode()
            {
                return start.GetHashCode() ^ length.GetHashCode();
            }
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    {
                        int cases = int.Parse(reader.ReadLine());
                        for (int i = 0; i < cases; i++)
                        {
                            int[] testData = reader.ReadLine().Split(null).Select(s => int.Parse(s)).ToArray();
                            int p = testData[0];
                            int q = testData[1];

                            int[] prisoners = reader.ReadLine().Split(null).Select(s => int.Parse(s) - 1).ToArray();

                            var cache = new Dictionary<Index, int>();

                            var result = FindMinimum(0, p, prisoners, cache);

                            writer.WriteLine("Case #" + (i + 1) + ": " + result);
                        }
                    }
                }
            }
        }

        public static int FindMinimum(int start, int end, int[] prisoners, Dictionary<Index, int> cache)
        {
            var key = new Index() { start = start, length = end - start };
            if (cache.ContainsKey(key))
                return cache[key];

            int result = int.MaxValue;

            for (int i = 0; i < prisoners.Length; i++)
            {
                var prisoner = prisoners[i];
                if (prisoner >= start && prisoner < end)
                {
                    var leftMinimum = FindMinimum(start, prisoner, prisoners, cache);
                    var rightMinimum = FindMinimum(prisoner + 1, end, prisoners, cache);
                    var currentMinimum = leftMinimum + rightMinimum + end - start - 1;
                    if (currentMinimum < result)
                        result = currentMinimum;
                }
            }

            if (result == int.MaxValue)
                result = 0;

            cache[key] = result;
            return result;
        }
    }
}
