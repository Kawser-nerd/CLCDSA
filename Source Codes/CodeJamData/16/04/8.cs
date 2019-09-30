using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Fractiles
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\D-small-attempt0.in";
            const string filename = @"..\..\D-large.in";

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

        private static long Get(int[] a, int bas)
        {
            long sum = 0;
            long p = 1;
            for (int i = a.Length - 1; i >= 0; i--)
            {
                sum += p*a[i];
                p *= bas;
            }
            return sum;
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int K = int.Parse(ss[0]);
            int C = int.Parse(ss[1]);
            int S = int.Parse(ss[2]);

            var list = new List<int[]>();
            int index = 0;
            for (int i = 0; i < K; i++)
            {
                if (index == 0)
                {
                    list.Add(new int[C]);
                }

                list[list.Count - 1][index] = i;
                index++;

                if (index == C)
                    index = 0;
            }
            if (list.Count <= S)
            {
                Console.Write("Case #{0}:", Case);
                writer.Write("Case #{0}:", Case);

                foreach (var intse in list)
                {
                    long v = Get(intse, K) + 1;
                    Console.Write(" {0}", v);
                    writer.Write(" {0}", v);
                }
                Console.WriteLine();
                writer.WriteLine();
            }
            else
            {
                Console.WriteLine("Case #{0}: IMPOSSIBLE", Case);
                writer.WriteLine("Case #{0}: IMPOSSIBLE", Case);
            }
        }
    }
}