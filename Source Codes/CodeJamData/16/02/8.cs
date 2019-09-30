using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Revenge_of_the_Pancakes
{
    internal class Program
    {
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
            string ss = reader.ReadLine();
            int time = 0;

            for (int i = 1; i < ss.Length; i++)
            {
                if (ss[i] != ss[i - 1])
                    time++;
            }

            if (ss[ss.Length - 1] == '-')
                time ++;


            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }
}