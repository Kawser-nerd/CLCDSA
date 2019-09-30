using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Fresh_Chocolate
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
            string[] ss = reader.ReadLine().Split(' ');

            int n = int.Parse(ss[0]);
            int p = int.Parse(ss[1]);

            ss = reader.ReadLine().Split(' ');

            var gr = new int[p];
            for (int i = 0; i < n; i++)
            {
                gr[int.Parse(ss[i])%p]++;
            }

            int time = gr[0];

            if (p == 2)
            {
                time += (gr[1] + 1)/2;
            }
            else if (p == 3)
            {
                int m = Math.Min(gr[1], gr[2]);
                gr[1] -= m;
                gr[2] -= m;
                time += m;

                time += (gr[1] + gr[2] + 2)/3;
            }
            else if (p == 4)
            {
                time += gr[2]/2;
                gr[2] = gr[2]%2;

                int m = Math.Min(gr[1], gr[3]);
                gr[1] -= m;
                gr[3] -= m;
                time += m;

                if (gr[2] == 1)
                {
                    if (gr[1] > 1)
                    {
                        time++;
                        gr[1] -= 2;
                        gr[2]--;
                    }
                    else if (gr[3] > 1)
                    {
                        time++;
                        gr[3] -= 2;
                        gr[2]--;
                    }
                }
                time += (gr[2]+gr[1] + gr[3] + 3)/4;
            }

            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }
}