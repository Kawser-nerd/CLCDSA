using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Haircut
{
    internal class Program
    {
        private static long N;
        private static long[] bb;

        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\B-small-attempt0.in";
            const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int B = int.Parse(ss[0]);

            N = int.Parse(ss[1]);


            bb = new long[B];
            ss = reader.ReadLine().Split(' ');

            long min = int.MaxValue;
            for (int i = 0; i < B; i++)
            {
                bb[i] = int.Parse(ss[i]);

                if (bb[i] < min)
                    min = bb[i];
            }


            int time = Find(0, 1 + min*N);

            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }

        private static int Find(long l, long r)
        {
            if (l == r)
            {
                long count = 0;
                for (int i = 0; i < bb.Length; i++)
                {
                    count += (l - 1)/bb[i] + 1;
                }
                long nn = N - count;
                int min = -1;
                long minv = long.MaxValue;
                long nnn = nn;
                for (int i = 0; i < bb.Length; i++)
                {
                    long delta = l - (l/bb[i])*bb[i];
                    if (delta < minv)
                    {
                        minv = delta;
                        min = i + 1;
                        nnn = nn-1;
                    }
                    else if (delta == minv && nnn > 0)
                    {
                        min = i + 1;
                        nnn--;
                    }
                }
                return min;
            }
            {
                long mid = (l + r)/2;
                long count = 0;
                for (int i = 0; i < bb.Length; i++)
                {
                    count += mid/bb[i] + 1;
                }

                if (count >= N)
                {
                    return Find(l, mid);
                }
                return Find(mid + 1, r);
            }
        }
    }
}