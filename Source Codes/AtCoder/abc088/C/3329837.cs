using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_087
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            var cs = new int[3, 3];
            for(int i = 0; i < 3; i++)
            {
                int[] input = ReadInts();
                cs[i, 0] = input[0];
                cs[i, 1] = input[1];
                cs[i, 2] = input[2];
            }

            int a1 = cs[0, 0];
            int a2 = cs[1, 0];
            int a3 = cs[2, 0];
            int b1 = 0;

            for(int i = 1; i < 3; i++)
            {
                int bi = cs[0, i] - cs[0, 0];
                for(int j = 1; j < 3; j++)
                {
                    if (bi == cs[j, i] - cs[j, 0])
                    {
                        continue;
                    }
                    else
                    {
                        Console.WriteLine("No");
                        return;
                    }
                }
            }

            Console.WriteLine("Yes");
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