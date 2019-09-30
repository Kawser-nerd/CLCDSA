using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _014_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] abc = ReadInts();
            if (abc[0]%2==0
                &&abc[0] == abc[1] && abc[1] == abc[2])
            {
                Console.WriteLine(-1);
                return;
            }
            int cnt = 0;
            while (abc[0] % 2 == 0 && abc[1] % 2 == 0 && abc[2] % 2 == 0)
            {
                int[] next = new int[3];
                next[0] = (abc[1] + abc[2])/2;
                next[1] = (abc[2] + abc[0])/2;
                next[2] = (abc[0] + abc[1])/2;
                abc = next;
                cnt++;
            }

            Console.WriteLine(cnt);
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