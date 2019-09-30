using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_016
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            double[] abs = ReadDoubles();
            int n = ReadInt();
            var xys = new double[n][];
            for(int i = 0; i < n; i++)
            {
                xys[i] = ReadDoubles();
            }

            if (abs[0] == abs[2] && abs[1] == abs[3])
            {
                Console.WriteLine(1);
                return;
            }

            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                int j = (i + 1) % n;
                //????
                cnt += IsCross(new double[2] { abs[0], abs[1] },
                    new double[2] { abs[2], abs[3] },
                    xys[i], xys[j]);
            }
            //Console.WriteLine(cnt);
            Console.WriteLine(cnt / 2 + 1);
        }

        static int IsCross(params double[][] poses)//???????
        {
            double sa = 0.5 * (
                (poses[2][0] - poses[0][0]) * (poses[1][1] - poses[0][1])
                - (poses[1][0] - poses[0][0]) * (poses[2][1] - poses[0][1]));
            double sb = 0.5 * (
                (poses[3][0] - poses[0][0]) * (poses[1][1] - poses[0][1])
                - (poses[1][0] - poses[0][0]) * (poses[3][1] - poses[0][1]));
            double sc = 0.5 * (
                (poses[0][0] - poses[2][0]) * (poses[3][1] - poses[2][1])
                - (poses[3][0] - poses[2][0]) * (poses[0][1] - poses[2][1]));
            double sd = 0.5 * (
                (poses[1][0] - poses[2][0]) * (poses[3][1] - poses[2][1])
                - (poses[3][0] - poses[2][0]) * (poses[1][1] - poses[2][1]));

            if (sa * sb < 0 && sc * sd < 0) return 1;
            else return 0;
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