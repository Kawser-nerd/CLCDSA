using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Bullseye
{
    class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            //string filename = @"A-small-attempt0.in.txt";
            string filename = @"A-large.in.txt";

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

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
            long r = long.Parse(s[0]);
            long t = long.Parse(s[1]);

            long count = 0;
            for (; ; r += 2)
            {
                if (r< long.MaxValue/2000 - 2000000 &&  t > (1999000 + 2000 * r))
                {
                    t -= 1999000 + 2000 * r;
                    count += 1000;
                    r += 2 * 999;
                }
                else
                {
                    t -= (2 * r + 1);
                    if (t < 0)
                    {
                        break;
                    }
                    count++;
                }
            }

            Console.WriteLine("Case #{0}: {1}", C, count);
            writer.WriteLine("Case #{0}: {1}", C, count);

        }
    }
}
