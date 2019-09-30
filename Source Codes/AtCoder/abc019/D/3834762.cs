using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_019
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int diameter = 0;
            int leafI = 0;
            int leafI2 = 0;
            for (int i = 1; i < n; i++)
            {
                Console.WriteLine("? {0} {1}", leafI + 1, i + 1);
                int dist1 = int.Parse(Console.ReadLine());

                Console.WriteLine("? {0} {1}", leafI2 + 1, i + 1);
                int dist2 = int.Parse(Console.ReadLine());

                if (dist1 > dist2 && dist1 > diameter)
                {
                    diameter = dist1;
                    leafI2 = i;
                }
                else if (dist2 >= dist1 && dist2 > diameter)
                {
                    diameter = dist2;
                    leafI = i;
                }
            }

            Console.WriteLine("! " + diameter);
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