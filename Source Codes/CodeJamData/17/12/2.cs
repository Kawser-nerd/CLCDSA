using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Ratatouille
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

        private static int Min(int p, int n)
        {
            return (10*p + 11*n - 1)/(11*n);
        }

        private static int Max(int p, int n)
        {
            return 10*p/(9*n);
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');

            int n = int.Parse(ss[0]);
            int p = int.Parse(ss[1]);

            var nn = new int[n];
            ss = reader.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                nn[i] = int.Parse(ss[i]);
            }

            var np = new int[n][];
            for (int i = 0; i < n; i++)
            {
                np[i] = new int[p];
                ss = reader.ReadLine().Split(' ');
                for (int j = 0; j < p; j++)
                {
                    np[i][j] = int.Parse(ss[j]);
                }
                Array.Sort(np[i]);
            }

            var minnp = new int[n][];
            for (int i = 0; i < n; i++)
            {
                minnp[i] = new int[p];
                for (int j = 0; j < p; j++)
                {
                    minnp[i][j] = Min(np[i][j], nn[i]);
                }
            }

            var maxnp = new int[n][];
            for (int i = 0; i < n; i++)
            {
                maxnp[i] = new int[p];
                for (int j = 0; j < p; j++)
                {
                    maxnp[i][j] = Max(np[i][j], nn[i]);
                }
            }

            var used = new bool[n][];
            var maxlist = new List<int>();
            for (int i = 0; i < n; i++)
            {
                used[i] = new bool[p];
                for (int j = 0; j < p; j++)
                {
                    if (maxnp[i][j] < minnp[i][j])
                        used[i][j] = true;
                    else
                    {
                        maxlist.Add(maxnp[i][j]);
                    }
                }
            }
            maxlist.Sort();
            int time = 0;
            foreach (int max in maxlist)
            {
                bool f = false;
                var indexs = new int[n];
                for (int i = 0; i < n; i++)
                {
                    f = false;
                    for (int j = 0; j < p; j++)
                    {
                        if (used[i][j])
                            continue;
                        if (maxnp[i][j] < max)
                            continue;
                        if (minnp[i][j] > max)
                            break;
                        f = true;
                        indexs[i] = j;
                        break;
                    }
                    if (!f)
                        break;
                }
                if (f)
                {
                    time++;
                    for (int i = 0; i < n; i++)
                    {
                        used[i][indexs[i]] = true;
                    }
                }
            }

            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }
}