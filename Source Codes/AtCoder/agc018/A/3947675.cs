using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _018_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];
            int[] array = ReadInts();
            Array.Sort(array);
            if (array[n - 1] < k)
            {
                Console.WriteLine("IMPOSSIBLE");
                return;
            }
            long gcd = array[0];
            for(int i = 1; i < n; i++)
            {
                gcd = GCD(gcd, array[i]);
            }
            if (k % gcd == 0)
            {
                Console.WriteLine("POSSIBLE");
            }
            else
            {
                Console.WriteLine("IMPOSSIBLE");
            }
        }
        
        static long GCD(long a, long b)
        {
            long c = b;
            do
            {
                c = a % b;
                a = b;
                b = c;
            } while (c > 0);
            return a;
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