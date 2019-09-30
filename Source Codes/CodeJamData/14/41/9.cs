using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Data_Packing
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
            int x = int.Parse(ss[1]);

            ss = reader.ReadLine().Split(' ');
            var nn = new int[n];
            for (int i = 0; i < n; i++)
            {
                nn[i] = int.Parse(ss[i]);
            }

            Array.Sort(nn);

            int index = 0;
            int index2 = n - 1;
            int count = 0;
            while (index <= index2)
            {
                if (nn[index2] + nn[index] <= x)
                {
                    index2--;
                    index++;
                    count++;
                }
                else
                {
                    index2--;
                    count++;
                }
            }


            Console.WriteLine("Case #{0}: {1}", Case, count);
            writer.WriteLine("Case #{0}: {1}", Case, count);
        }
    }
}