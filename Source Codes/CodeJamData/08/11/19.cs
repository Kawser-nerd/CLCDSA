using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem1
{
    class Program1
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(args[0]))
            {
                using (StreamWriter sw = new StreamWriter(args[1]))
                {
                    string cases = sr.ReadLine();
                    int N = int.Parse(cases);
                    for (int i = 0; i < N; i++)
                    {
                        int count = int.Parse(sr.ReadLine());
                        long[] x = ParseLongs(sr.ReadLine(), count);
                        long[] y = ParseLongs(sr.ReadLine(), count);
                        sw.WriteLine("Case #{0}: {1}", i + 1, Calculate(x, y));
                    }
                }
            }
        }

        private static long[] ParseLongs(string line, int count)
        {
            string[] split = line.Split(' ');
            long[] ret = new long[count];

            for (int i = 0; i < ret.Length; i++)
                ret[i] = long.Parse(split[i]);

            return ret;
        }

        private static long Calculate(long[] x, long[] y)
        {
            Array.Sort<long>(x);
            Array.Sort<long>(y);
            Array.Reverse(y);

            long sum = 0;
            for (int i = 0; i < x.Length; i++)
                sum += x[i] * y[i];

            return sum;
        }
    }
}
