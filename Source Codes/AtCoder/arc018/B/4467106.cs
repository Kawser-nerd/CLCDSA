using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _018
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[][] poses = new int[n][];
            for (int i = 0; i < n; i++) poses[i] = ReadInts();
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    for(int k = j+1; k < n; k++)
                    {
                        long x2 = poses[j][0] - poses[i][0];
                        long y2 = poses[j][1] - poses[i][1];
                        long x3 = poses[k][0] - poses[i][0];
                        long y3 = poses[k][1] - poses[i][1];
                        if ((x2 * y3 - x3 * y2)!=0
                            && (x2 * y3 - x3 * y2) % 2 == 0) cnt++;
                    }
                }
            }
            WriteLine(cnt);
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}