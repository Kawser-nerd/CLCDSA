using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Rather_Perplexing_Showdown
{
    internal class Program
    {
        private static readonly List<List<Tuple<int, int, int, char>>> list = new List<List<Tuple<int, int, int, char>>>();

        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\A-small-attempt0.in";
            const string filename = @"..\..\A-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            Init();


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

        private static void Init()
        {
            list.Add(new List<Tuple<int, int, int, char>>
                         {
                             new Tuple<int, int, int, char>(1, 0, 0, 'R'),
                             new Tuple<int, int, int, char>(0, 1, 0, 'P'),
                             new Tuple<int, int, int, char>(0, 0, 1, 'S')
                         });
            for (int i = 0; i < 12; i++)
            {
                var t = new List<Tuple<int, int, int, char>>();
                foreach (var tuple in list[i])
                {
                    t.Add(new Tuple<int, int, int, char>(tuple.Item1 + tuple.Item2, tuple.Item3 + tuple.Item2, tuple.Item1 + tuple.Item3, tuple.Item4));
                }
                list.Add(t);
            }
        }

        private static string Build(char c, int n)
        {
            if (n == 0)
                return new string(c, 1);

            string s1 = Build(c, n - 1);
            string s2;
            if (c == 'R')
                s2 = Build('S', n - 1);
            else if (c == 'P')
                s2 = Build('R', n - 1);
            else
                s2 = Build('P', n - 1);


            string ss1 = s1 + s2;
            string ss2 = s2 + s1;
            if (string.Compare(ss1, ss2) == -1)
            {
                return ss1;
            }
            return ss2;
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');

            int N = int.Parse(ss[0]), R = int.Parse(ss[1]), P = int.Parse(ss[2]), S = int.Parse(ss[3]);

            foreach (var tuple in list[N])
            {
                if (tuple.Item1 == R && tuple.Item2 == P && tuple.Item3 == S)
                {
                    string s = Build(tuple.Item4, N);

                    Console.WriteLine("Case #{0}: {1}", Case, s);
                    writer.WriteLine("Case #{0}: {1}", Case, s);
                    return;
                }
            }

            Console.WriteLine("Case #{0}: IMPOSSIBLE", Case);
            writer.WriteLine("Case #{0}: IMPOSSIBLE", Case);
        }
    }
}