using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Close_Match
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\B-small-attempt0.in";
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

            int max = int.Parse(new string('9', ss[0].Length));
            string format = new string('0',ss[0].Length);
            int min = int.MaxValue;

            int mi=0, mj=0;
            for (int i = 0; i <= max; i++)
            {
                string si = i.ToString(format);
                bool ok = true;
                for (int j = 0; j < si.Length; j++)
                {
                    if (ss[0][j] != '?' && ss[0][j] != si[j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int j = 0; j <= max; j++)
                    {
                        string sj = j.ToString(format);
                         ok = true;
                        for (int jj = 0; jj < si.Length; jj++)
                        {
                            if (ss[1][jj] != '?' && ss[1][jj] != sj[jj])
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (ok && Math.Abs(i - j) < min)
                        {
                            min = Math.Abs(i - j);
                            mi = i;
                            mj = j;
                        }
                    }
                }
            }

            Console.WriteLine("Case #{0}: {1} {2}", Case, mi.ToString(format), mj.ToString(format));
            writer.WriteLine("Case #{0}: {1} {2}", Case, mi.ToString(format), mj.ToString(format));
        }
    }
}