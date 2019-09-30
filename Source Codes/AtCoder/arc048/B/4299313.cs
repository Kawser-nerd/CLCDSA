using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _048
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[][] rhn = new int[n][];
            for(int i = 0; i < n; i++)
            {
                int[] rh = ReadInts();
                rhn[i] = new int[3] { rh[0], rh[1]-1, i };
            }
            Array.Sort(rhn, (a, b) => a[0] - b[0]);
            var dict = new Dictionary<int, int[]>();
            for (int i = 0; i < n; i++)
            {
                if (!dict.ContainsKey(rhn[i][0]))
                {
                    dict.Add(rhn[i][0], new int[3]);
                }
                dict[rhn[i][0]][rhn[i][1]]++;
            }
            int[] afterSames = new int[n];
            int cnt = 0;
            for(int i = n - 2; i >= 0; i--)
            {
                if (rhn[i][0] == rhn[i+1][0])
                {
                    cnt++;
                }
                else
                {
                    cnt = 0;
                }
                afterSames[i] = cnt;
            }
            int[] beforeSames = new int[n];
            cnt = 0;
            for (int i = 1; i <n; i++)
            {
                if (rhn[i][0] == rhn[i - 1][0])
                {
                    cnt++;
                }
                else
                {
                    cnt = 0;
                }
                beforeSames[i] = cnt;
            }
            int[][] res = new int[n][];
            for(int i = 0; i <n; i++)
            {
                int index = rhn[i][2];
                int r = rhn[i][0];
                int h = rhn[i][1];
                res[index] = new int[3];
                res[index][0] = dict[r][(h + 1) % 3];
                res[index][0] += i - (beforeSames[i]);
                res[index][1] = dict[r][(h + 2) % 3];
                res[index][1] += n - 1 - i - afterSames[i];
                res[index][2] = dict[r][h]-1;
            }

            for(int i = 0; i < n; i++)
            {
                Console.WriteLine(
                    res[i][0] + " " + res[i][1] + " " + res[i][2]);
            }
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}