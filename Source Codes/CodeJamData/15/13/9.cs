using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Logging
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\C-small-attempt0.in";
            //const string filename = @"..\..\B-large.in";

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
            int N = int.Parse(reader.ReadLine());
            string[] ss;

            var X = new int[N];
            var Y = new int[N];

            for (int i = 0; i < N; i++)
            {
                ss = reader.ReadLine().Split(' ');
                X[i] = int.Parse(ss[0]);
                Y[i] = int.Parse(ss[1]);
            }

            Console.WriteLine("Case #{0}:", Case);
            writer.WriteLine("Case #{0}:", Case);


            for (int i = 0; i < N; i++)
            {
                int min = N;

                for (int j = 0; j < N; j++)
                {
                    if (j == i)
                        continue;

                    int pcount = 0;
                    int mcount = 0;

                    long dx = X[j] - X[i];
                    long dy = Y[j] - Y[i];

                    for (int k = 0; k < N; k++)
                    {
                        if (k == j || k == i)
                            continue;

                        long kx = X[k] - X[i];
                        long ky = Y[k] - Y[i];

                        long sum = dx*ky - dy*kx;
                        if (sum > 0)
                            pcount++;
                        else
                        {
                            mcount++;
                        }
                    }

                    min = Math.Min(min, Math.Min(pcount, mcount));
                }

                if (min == N)
                    min = 0;

                Console.WriteLine("{0}", min);
                writer.WriteLine("{0}", min);
            }
        }
    }
}