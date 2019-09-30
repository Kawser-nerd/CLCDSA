using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var A = ReadArrayInt();
            var exists = new bool[8];
            var free = 0;
            for (int i = 0; i < A.Length; i++)
            {
                if (A[i] < 400) exists[0] = true;
                else if (A[i] < 800) exists[1] = true;
                else if (A[i] < 1200) exists[2] = true;
                else if (A[i] < 1600) exists[3] = true;
                else if (A[i] < 2000) exists[4] = true;
                else if (A[i] < 2400) exists[5] = true;
                else if (A[i] < 2800) exists[6] = true;
                else if (A[i] < 3200) exists[7] = true;
                else free++;
            }
            int min = 0, max = 0;
            if(exists.Count(b => b) > 0)
            {
                min = exists.Count(b => b);
                max = min + free;
            }
            else
            {
                min = 1;
                max = free;
            }

            Console.WriteLine(min + " " + max);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}