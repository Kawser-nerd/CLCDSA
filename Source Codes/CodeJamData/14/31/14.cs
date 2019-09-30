using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Part_Elf
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

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split('/');

            long n1 = long.Parse(ss[0]);
            long n2 = long.Parse(ss[1]);

            long gcd = gds(n1, n2);
            n1 /= gcd;
            n2 /= gcd;


            if ((n2 & (n2 - 1)) != 0 || n1 > n2)
            {
                Console.WriteLine("Case #{0}: impossible", Case);
                writer.WriteLine("Case #{0}: impossible", Case);
                return;
            }

            int count = 0;
            long power = 1;
            while (power <= n2)
            {
                if (power > n1)
                    count++;
                power <<= 1;
            }

            Console.WriteLine("Case #{0}: {1}", Case, count);
            writer.WriteLine("Case #{0}: {1}", Case, count);
        }

        private static long gds(long a, long b)
        {
            return b == 0 ? a : gds(b, a%b);
        }
    }
}