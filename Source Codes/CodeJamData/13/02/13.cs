using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Helpers;

namespace _2013Q2
{
    class Program
    {
        static void Main()
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            System.Threading.Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-US");
            double lastMs = 0;
            Stopwatch sw = new Stopwatch();
            sw.Start();

            var inFileName = "A.in";
            var outFileName = inFileName.Replace(".in", "_out.out");
            using (var reader = new StreamReader(inFileName))
            using (var writer = new StreamWriter(outFileName))
            {
                int numTests = reader.ReadLineAsInt();

                for (int testcase = 1; testcase <= numTests; testcase++)
                {
                    int[] NM = reader.ReadLineAsIntArray();
                    int N = NM[0];
                    int M = NM[1];

                    int[,] map = new int[N, M];

                    for (int j = 0; j < N; j++)
                    {
                        int[] line = reader.ReadLineAsIntArray();

                        for (int k = 0; k < M; k++)
                        {
                            map[j, k] = line[k];
                        }
                    }

                    var result = String.Format("Case #{0}: {1}", testcase, Solve(N, M, map));
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static string Solve(int N, int M, int[,] map)
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                {
                    if (!CanCut(i, j, N, M, map))
                        return "NO";
                }

            return "YES";
        }

        private static bool CanCut(int i, int j, int N, int M, int[,] map)
        {
            int rowMax = GetMaxFromRow(i, M, map);
            int colMax = GetMaxFromCol(j, N, map);

            return (rowMax == map[i, j] || colMax == map[i, j]);
        }

        private static int GetMaxFromRow(int num, int N, int[,] map)
        {
            int max = 0;
            for (int i = 0; i < N; i++)
            {
                if (max < map[num, i])
                    max = map[num, i];
            }
            return max;
        }

        private static int GetMaxFromCol(int num, int M, int[,] map)
        {
            int max = 0;
            for (int i = 0; i < M; i++)
            {
                if (max < map[i, num])
                    max = map[i, num];
            }
            return max;
        }
    }
}
