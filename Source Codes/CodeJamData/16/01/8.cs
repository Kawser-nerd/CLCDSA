using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Counting_Sheep
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\A-small-attempt0.in";
            const string filename = @"..\..\A-large.in";

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

        private static long Solve(long n)
        {
            var mask = new bool[10];
            int filled = 0;

            for (int i = 1;; i++)
            {
                long k = i*n;
                while (k > 0)
                {
                    long d = k%10;
                    if (!mask[d])
                    {
                        filled++;
                        if (filled == 10)
                            return i*n;
                        mask[d] = true;
                    }
                    k /= 10;
                }
            }
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            long n = long.Parse(reader.ReadLine());

            if (n == 0)
            {
                Console.WriteLine("Case #{0}: INSOMNIA", Case);
                writer.WriteLine("Case #{0}: INSOMNIA", Case);
                return;
            }

            long last = Solve(n);

            Console.WriteLine("Case #{0}: {1}", Case, last);
            writer.WriteLine("Case #{0}: {1}", Case, last);
        }
    }
}