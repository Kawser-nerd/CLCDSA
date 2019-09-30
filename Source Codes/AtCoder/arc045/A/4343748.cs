using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _045
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] s = Read().Split();
            for(int i = 0; i < s.Length; i++)
            {
                switch (s[i][0])
                {

                    case 'L':
                        Console.Write('<');
                        break;
                    case 'R':
                        Console.Write('>');
                        break;
                    case 'A':
                        Console.Write('A');
                        break;
                }
                if (i < s.Length - 1) Console.Write(' ');
            }
            Console.WriteLine();
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