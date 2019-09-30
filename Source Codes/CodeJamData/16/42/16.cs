using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Red_Tape_Committee
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\B-small-attempt3.in";
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

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int n = int.Parse(ss[0]);
            int k = int.Parse(ss[1]);

            ss = reader.ReadLine().Split(' ');
            var nn = new double[n];

            for (int i = 0; i < n; i++)
            {
                nn[i] = double.Parse(ss[i]);
            }

            //var p = new double[n,n];

            //for (int i = 0; i < n; i++)
            //{
            //    for (int j = i + 1; j < n; j++)
            //    {
            //        p[i, j] = nn[i]*(1 - nn[j]) + nn[j]*(1 - nn[i]);
            //    }
            //}

            var f = new bool[n];
            //for (int kk = k; kk < n; kk++)
            //{
            //    var pn = new double[n];
            //    for (int i = 0; i < n; i++)
            //    {
            //        if (f[i])
            //            continue;
            //        for (int j = i + 1; j < n; j++)
            //        {
            //            if (f[j])
            //                continue;
            //            pn[i] += p[i, j];
            //            pn[j] += p[i, j];
            //        }
            //    }

            //    double min = 500;
            //    int mi = -1;
            //    for (int i = 0; i < n; i++)
            //    {
            //        if (f[i])
            //            continue;
            //        if (pn[i] < min)
            //        {
            //            mi = i;
            //            min = pn[i];
            //        }
            //    }
            //    f[mi] = true;
            //}

            int maxmask = 1 << n;
            double time = 0;

            for (int ii = 0; ii < maxmask; ii++)
            {
                if (SparseBitcount(ii) != k)
                    continue;

               

                f = new bool[n];
                for (int j = 0; j < n; j++)
                {
                    if ((ii & (1 << j)) != 0)
                    {
                        f[j] = true;
                    }
                }

                var p = new double[n+1, n+1];
                p[0, 0] = 1;
                double sum = 0;
                int m = 0;
                for (int i = 0; i < n; i++)
                {
                    if (!f[i])
                        continue;

                    m++;

                    for (int j = 0; j < n; j++)
                    {
                        p[j,m]=p[j,m-1]*(1-nn[i]);
                        if (j>0)
                            p[j, m] += p[j-1, m - 1] * nn[i];
                    }

                }
                sum = p[k/2,m];
                if (time < sum)
                    time = sum;
            }


            //int count = 0;
            //for (int i = 0; i < n; i++)
            //{
            //    if (f[i])
            //        continue;
            //    for (int j = i + 1; j < n; j++)
            //    {
            //        if (f[j])
            //            continue;

            //        time += p[i, j];
            //        count++;
            //    }
            //}

            //time /= count;

            Console.WriteLine("Case #{0}: {1:#0.0000000}", Case, time);
            writer.WriteLine("Case #{0}: {1:#0.0000000}", Case, time);
        }

        private static int SparseBitcount(int n)
        {
            int count = 0;
            while (n != 0)
            {
                count++;
                n &= (n - 1);
            }
            return count;
        }
    }
}