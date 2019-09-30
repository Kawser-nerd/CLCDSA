using System;
using System.IO;

namespace Lawnmower
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            //string filename = @"B-small-attempt0.in.txt";
            string filename = @"B-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
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

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            bool ok = true;

            string[] ss = reader.ReadLine().Split(' ');
            int N = int.Parse(ss[0]);
            int M = int.Parse(ss[1]);

            var nn = new int[N,M];
            var fnn = new bool[N, M];

            for (int i = 0; i < N; i++)
            {
                ss = reader.ReadLine().Split(' ');
                for (int j = 0; j < M; j++)
                {
                    nn[i, j] = int.Parse(ss[j]);
                }
            }

            for (int i = 0; i < N; i++)
            {
                int max = 0;
                for (int j = 0; j < M; j++)
                {
                    if (max < nn[i, j])
                        max = nn[i, j];
                }

                for (int j = 0; j < M; j++)
                {
                    if (max == nn[i, j])
                        fnn[i, j] = true;
                }
            }

            for (int i = 0; i < M; i++)
            {
                int max = 0;
                for (int j = 0; j < N; j++)
                {
                    if (max < nn[j, i])
                        max = nn[j, i];
                }

                for (int j = 0; j < N; j++)
                {
                    if (max == nn[j, i])
                        fnn[j, i] = true;
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (!fnn[i,j])
                    {
                        ok = false;
                        goto fin;
                    }
                }
            }


            fin:
            Console.WriteLine("Case #{0}: {1}", C, ok ? "YES" : "NO");
            writer.WriteLine("Case #{0}: {1}", C, ok ? "YES" : "NO");
        }
    }
}