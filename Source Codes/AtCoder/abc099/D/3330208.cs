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

            var errors = new int[3][][];//????????????
            for(int i = 0; i < 3; i++)
            {
                errors[i] = new int[c][];
                for(int j = 0; j < c; j++)
                {
                    errors[i][j] = new int[2];
                    errors[i][j][0] = j;
                    errors[i][j][1] = 0;
                    for(int k = 0; k < c; k++)
                    {//?k???j?????????????
                        errors[i][j][1] += colors[i, k] * ds[k, j];
                    }
                }
            }
            Array.Sort(errors[0], (a, b) => a[1] - b[1]);
            Array.Sort(errors[1], (a, b) => a[1] - b[1]);
            Array.Sort(errors[2], (a, b) => a[1] - b[1]);
            int minErrorSum = int.MaxValue;
            for(int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {

                    for (int k = 0; k < 3; k++)
                    {
                        if(errors[0][i][0]==errors[1][j][0]
                            || errors[1][j][0] == errors[2][k][0]
                            || errors[2][k][0] == errors[0][i][0])
                        {
                            continue;
                        }
                        else
                        {
                            int errorSum = errors[0][i][1]
                                + errors[1][j][1]
                                + errors[2][k][1];
                            minErrorSum = Math.Min(minErrorSum, errorSum);
                        }
                    }
                }
            }

            Console.WriteLine(minErrorSum);
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