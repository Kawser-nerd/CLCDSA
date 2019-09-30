using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace The_Repeater
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\A-small-attempt0.in";
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


        private static string gett(string t, List<int> counts)
        {
            var b = new StringBuilder();

            char last = '1';
            int count = 1;
            for (int i = 0; i < t.Length; i++)
            {
                if (last != t[i])
                {
                    if (last != '1')
                        counts.Add(count);
                    last = t[i];
                    b.Append(last);
                    
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            counts.Add(count);

            return b.ToString();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            int N = int.Parse(reader.ReadLine());
            var ss = new string[N];
            var templates = new string[N];
            var counts = new List<int>[N];
            for (int i = 0; i < N; i++)
            {
                ss[i] = reader.ReadLine();
                counts[i] = new List<int>();
                templates[i] = gett(ss[i], counts[i]);
            }

            for (int i = 1; i < N; i++)
            {
                if (templates[i] != templates[i - 1])
                {
                    Console.WriteLine("Case #{0}: Fegla Won", Case);
                    writer.WriteLine("Case #{0}: Fegla Won", Case);
                    return;
                }
            }

            int time = 0;

            for (int i = 0; i < templates[0].Length; i++)
            {
                int sum = 0;
                for (int j = 0; j < counts.Length; j++)
                {
                    sum += counts[j][i];
                }
                int avg = sum/counts.Length;
                int s1 = 0;
                int s2 = 0;
                for (int j = 0; j < counts.Length; j++)
                {
                    s1 += Math.Abs(counts[j][i]-avg);
                    s2 += Math.Abs(counts[j][i] - avg-1);
                }
                if (s1<s2)
                {
                    time += s1;
                }
                else
                {
                    time += s2;
                }
            }
            


            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }
}