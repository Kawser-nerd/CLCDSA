using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Mushroom_Monster
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\A-small-attempt1.in";
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
            int n = int.Parse(reader.ReadLine());
            string[] ss = reader.ReadLine().Split(' ');
            var nn = new int[n];
            for (int i = 0; i < n; i++)
            {
                nn[i] = int.Parse(ss[i]);
            }

            long time1 = 0;
            long time2 = 0;

            int maxspeed = 0;

            for (int i = 1; i < n; i++)
            {
                int delta = -nn[i] + nn[i - 1];
                if (delta > 0)
                {
                    time1 += delta;
                    if (delta > maxspeed)
                        maxspeed = delta;
                }
            }

            long count = nn[0];
            for (int i = 1; i < n; i++)
            {
                if (count >= maxspeed)
                {
                    time2 += maxspeed;
                    count = nn[i];
                }
                else
                {
                    time2 += count;
                    count = nn[i];
                }
            }

            Console.WriteLine("Case #{0}: {1} {2}", Case, time1, time2);
            writer.WriteLine("Case #{0}: {1} {2}", Case, time1, time2);
        }
    }
}