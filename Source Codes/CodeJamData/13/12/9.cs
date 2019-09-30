using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Manage_your_Energy
{
    class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"B-small-attempt0.in.txt";
            //string filename = @"A-small-attempt0.in.txt";
            //string filename = @"A-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
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
        static int[] nn;
        static int E;
        static int R;
        static long max(int index, int count)
        {
            int maxc = Math.Min(E, count + R);
            if (index == nn.Length - 1)
            {
                return nn[index] * maxc;
            }

            long maxx = 0;
            for (int i = 0; i <= maxc; i++)
            {
                long m = nn[index] * i + max(index + 1, maxc - i);
                if (m > maxx)
                    maxx = m;
            }

            return maxx;
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
             E = int.Parse(s[0]);
             R = int.Parse(s[1]);
            int N = int.Parse(s[2]);

             nn = new int[N];
            s = reader.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                nn[i] = int.Parse(s[i]);
            }

            long count = max(0, E);


            Console.WriteLine("Case #{0}: {1}", C, count);
            writer.WriteLine("Case #{0}: {1}", C, count);

        }
    }
}
