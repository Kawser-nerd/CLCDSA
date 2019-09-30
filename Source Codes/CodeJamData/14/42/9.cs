using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Up_and_Down
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\B-small-attempt2.in";
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
            int n = int.Parse(reader.ReadLine());
            var nn = new int[n];
            string[] ss = reader.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                nn[i] = int.Parse(ss[i]);
            }
            var list = new List<pair>();
            for (int i = 0; i < n; i++)
            {
                list.Add(new pair(nn[i], i));
            }
            list.Sort(list[0]);
            for (int i = 0; i < n; i++)
            {
                nn[list[i].index] = i;
            }

            //List<int> big = GetLong(nn);
            //var nnn = (int[]) nn.Clone();
            //Array.Reverse(nnn);
            //List<int> small = GetLong(nnn);

            //if (big.Count>small.Count)
            //{

            //}

            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                int ml = 0;
                for (int j = 0; j < i; j++)
                {
                    if (nn[j] > nn[i])
                        ml++;
                }
                int mr = 0;
                for (int j = i + 1; j < n; j++)
                {
                    if (nn[j] > nn[i])
                        mr++;
                }
                sum += Math.Min(ml, mr);
            }


            int maxtime = 0;
            Console.WriteLine("Case #{0}: {1}", Case, sum);
            writer.WriteLine("Case #{0}: {1}", Case, sum);
        }

        private static List<int> GetLong(int[] nn)
        {
            int[] d = new int[nn.Length + 1], p = new int[nn.Length + 1]; // константа MAXN равна наибольшему возможному значению n

            for (int i = 0; i < nn.Length; ++i)
            {
                d[i] = 1;
                p[i] = -1;
                for (int j = 0; j < i; ++j)
                    if (nn[j] < nn[i])
                        if (1 + d[j] > d[i])
                        {
                            d[i] = 1 + d[j];
                            p[i] = j;
                        }
            }

            int ans = d[0], pos = 0;
            for (int i = 0; i < nn.Length; ++i)
                if (d[i] > ans)
                {
                    ans = d[i];
                    pos = i;
                }

            var path = new List<int>();
            while (pos != -1)
            {
                path.Add(pos);
                pos = p[pos];
            }
            path.Reverse();
            return path;
        }

        #region Nested type: pair

        private class pair : IComparer<pair>
        {
            public readonly int index;
            public readonly int val;

            public pair(int val, int index)
            {
                this.val = val;
                this.index = index;
            }

            #region IComparer<pair> Members

            public int Compare(pair x, pair y)
            {
                return x.val.CompareTo(y.val);
            }

            #endregion
        }

        #endregion
    }
}