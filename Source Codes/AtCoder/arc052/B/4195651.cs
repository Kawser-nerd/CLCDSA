using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _052
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nq = ReadInts();
            int n = nq[0];
            int q = nq[1];
            int[][] xrhs = new int[n][];
            for(int i = 0; i < n; i++)
            {
                xrhs[i] = ReadInts();
            }
            int[][] abs = new int[q][];
            for(int i = 0; i < q; i++)
            {
                abs[i] = ReadInts();
            }
            for(int i = 0; i < q; i++)
            {
                double res = 0;
                int a = abs[i][0];
                int b = abs[i][1];
                for(int j = 0; j < n; j++)
                {
                    int x = xrhs[j][0];
                    int r = xrhs[j][1];
                    int h = xrhs[j][2];
                    if (b <= x || x + h <= a) continue;
                    double ra = a <= x ? r : 1.0 * (x + h - a) * r / h;
                    double ha = a <= x ? h : (x + h - a);
                    double rb = b <= x + h ? 1.0 * (x + h - b) * r / h : 0;
                    double hb = b <= x + h ? x + h - b : 0;
                    res += ra * ra * ha;
                    res -= rb * rb * hb;
                }
                Console.WriteLine(res * Math.PI / 3);
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