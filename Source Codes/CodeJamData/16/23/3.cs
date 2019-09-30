using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Threading;

namespace Technobabble
{
    internal class Program
    {
        private static List<int>[] nn;
        private static bool[] used;
        private static int[] mt;

        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\C-small-attempt0.in";
            const string filename = @"..\..\C-large.in";

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

            var array = new Tuple<string, string>[n];
            for (int i = 0; i < n; i++)
            {
                string[] ss = reader.ReadLine().Split(' ');
                array[i] = new Tuple<string, string>(ss[0], ss[1]);
            }

            var d1 = new Dictionary<string, int>();
            var d2 = new Dictionary<string, int>();

            foreach (var tuple in array)
            {
                if (d1.ContainsKey(tuple.Item1))
                    d1[tuple.Item1] = 1 + d1[tuple.Item1];
                else
                {
                    d1[tuple.Item1] = 1;
                }
            }
            foreach (var tuple in array)
            {
                if (d2.ContainsKey(tuple.Item2))
                    d2[tuple.Item2] = 1 + d2[tuple.Item2];
                else
                {
                    d2[tuple.Item2] = 1;
                }
            }

            int time = 0;
            foreach (var tuple in array)
            {
                if (d1[tuple.Item1] == 1)
                {
                    time++;
                    d2.Remove(tuple.Item2);
                    d1.Remove(tuple.Item1);
                }
            }
            foreach (var tuple in array)
            {
                if (d2.ContainsKey(tuple.Item2) && d2[tuple.Item2] == 1)
                {
                    time++;
                    d1.Remove(tuple.Item1);
                    d2.Remove(tuple.Item2);
                }
            }
            int k = 0;
            foreach (string key in d1.Keys.ToList())
            {
                d1[key] = k++;
            }
            int kk = k;
            foreach (string key in d2.Keys.ToList())
            {
                d2[key] = k++;
            }

            nn = new List<int>[k];
            for (int i = 0; i < nn.Length; i++)
            {
                nn[i] = new List<int>();
            }

            foreach (var tuple in array)
            {
                if (d1.ContainsKey(tuple.Item1) && d2.ContainsKey(tuple.Item2))
                {
                    int a = d1[tuple.Item1];
                    int b = d2[tuple.Item2];

                    nn[a].Add(b);
                    nn[b].Add(a);
                }
            }

            used = new bool[k];
            mt = new int[k];
            for (int i = 0; i < kk; i++)
            {
                mt[i] = -1;
            }

            var used1 = new bool[k];
            for (int i = 0; i < k; ++i)
                for (int j = 0; j < nn[i].Count; ++j)
                    if (mt[nn[i][j]] == -1)
                    {
                        mt[nn[i][j]] = i;
                        used1[i] = true;
                        break;
                    }
            for (int i = 0; i < k; ++i)
            {
                if (used1[i]) continue;

                used = new bool[k];
                try_kuhn(i);
            }
            int count = 0;
            for (int i = 0; i < kk; i++)
            {
                if (mt[i] != -1)
                    count++;
            }
            time += k - count;

            Console.WriteLine("Case #{0}: {1}", Case, n - time);
            writer.WriteLine("Case #{0}: {1}", Case, n - time);
        }

        private static bool try_kuhn(int v)
        {
            if (used[v]) return false;
            used[v] = true;
            for (int i = 0; i < nn[v].Count; ++i)
            {
                int to = nn[v][i];
                if (mt[to] == -1 || try_kuhn(mt[to]))
                {
                    mt[to] = v;
                    return true;
                }
            }
            return false;
        }
    }
}