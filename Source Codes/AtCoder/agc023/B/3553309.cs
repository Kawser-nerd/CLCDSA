using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_B
{
    class _023
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var sGrid = new char[n * 2, n * 2];
            for (int i = 0; i < n; i++)
            {
                string s = Read();
                for (int j = 0; j < n; j++)
                {
                    sGrid[i, j] = s[j];
                    sGrid[i, j + n] = s[j];
                    sGrid[i + n, j] = s[j];
                    sGrid[i + n, j  + n] = s[j];
                }
            }
            /*
            for(int i = 0; i < n * 2; i++)
            {
                for(int j = 0; j < n * 2; j++)
                {
                    Console.Write(sGrid[i, j] + " ");
                }
                Console.WriteLine();
            }
            */
            int res = 0;
            int tarCnt = (n * n - n) / 2;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                for (int k = 1; k < n; k++)
                {
                    for (int l = 0; l < k; l++)
                    {
                        if (sGrid[i + k, l] == sGrid[i + l, k])
                        {
                            cnt++;
                        }
                    }
                }
                if (cnt == tarCnt) res += n - i;
            }
            for (int i = 1; i < n; i++)
            {
                int cnt = 0;
                for (int k = 1; k < n; k++)
                {
                    for (int l = 0; l < k; l++)
                    {
                        if (sGrid[k, i + l] == sGrid[l, i + k])
                        {
                            cnt++;
                        }
                    }
                }
                if (cnt == tarCnt) res += n - i;
            }
            Console.WriteLine(res);
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