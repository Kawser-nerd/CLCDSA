using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_039
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] hw = ReadInts();
            var sGrid = new bool[hw[0], hw[1]];
            for (int i = 0; i < hw[0]; i++)
            {
                string s = Read();
                for (int j = 0; j < hw[1]; j++)
                {
                    sGrid[i, j] = s[j] == '#';
                }
            }

            var origin = new bool[hw[0], hw[1]];
            for (int i = 0; i < hw[0]; i++)
            {
                for (int j = 0; j < hw[1]; j++)
                {
                    int cnt = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        for (int l = 0; l < 3; l++)
                        {
                            int ii = i - 1 + k;
                            int jj = j - 1 + l;
                            if (ii < 0 || ii == hw[0]
                                || jj < 0 || jj == hw[1])
                            {
                                cnt++;
                            }
                            else if (sGrid[ii, jj]) cnt++;
                        }
                    }
                    if (cnt == 9)
                    {
                        origin[i, j] = true;
                    }
                }
            }

            for (int i = 0; i < hw[0]; i++)
            {
                for (int j = 0; j < hw[1]; j++)
                {
                    bool black = false;
                    for (int k = 0; k < 3; k++)
                    {
                        for (int l = 0; l < 3; l++)
                        {
                            int ii = i - 1 + k;
                            int jj = j - 1 + l;
                            if (ii < 0 || ii == hw[0]
                                || jj < 0 || jj == hw[1])
                            {
                                continue;
                            }

                            if (origin[ii, jj]) black = true;
                        }
                    }
                    if (black !=sGrid[i, j])
                    {
                        Console.WriteLine("impossible");
                        return;
                    }
                }
            }

            Console.WriteLine("possible");
            for (int i = 0; i < hw[0]; i++)
            {
                for (int j = 0; j < hw[1]; j++)
                {
                    Console.Write(origin[i, j] ? '#' : '.');
                }
                Console.WriteLine();
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