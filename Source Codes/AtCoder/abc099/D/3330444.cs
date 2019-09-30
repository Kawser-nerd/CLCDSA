using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_099
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nc = ReadInts();
            int n = nc[0];
            int c = nc[1];
            var ds = new int[c, c];
            for (int i = 0; i < c; i++)
            {
                int[] input = ReadInts();
                for(int j = 0; j < c; j++)
                {
                    ds[i, j] = input[j];
                }
            }

            var cs = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                int[] input = ReadInts();
                for (int j = 0; j < n; j++)
                {
                    cs[i, j] = input[j];
                }
            }

            var colors = new int[3,c];//???????
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    colors[(i + j) % 3, cs[i, j] - 1]++;
                }
            }

            var errors = new int[3, c];
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    errors[i,j] = 0;
                    for(int k = 0; k < c; k++)
                    {//?k??j????
                        errors[i, j] += colors[i, k] * ds[k, j];
                    }
                }
            }

            int minError = int.MaxValue;
            for(int i = 0; i < c; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    if (i == j) continue;

                    for(int k = 0; k < c; k++)
                    {
                        if (i == k || j == k) continue;

                        int errorSum 
                            = errors[0, i] + errors[1, j] + errors[2, k];
                        minError = Math.Min(minError, errorSum);
                    }
                }
            }

            Console.WriteLine(minError);
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