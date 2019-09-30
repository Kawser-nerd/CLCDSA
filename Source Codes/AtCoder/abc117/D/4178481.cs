using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayLong();
            var N = input[0];
            var K = input[1];
            var A = ReadArrayLong();
            var keta = 0;
            for (int i = 0; Math.Pow(2, i) <= Math.Pow(10, 12); i++) keta++;
            var cnt = new int[keta];
            for (int i = 0; i < keta; i++)
            {
                var chk = 1L;
                for (int j = 0; j < i; j++) chk <<= 1;
                for (int j = 0; j < N; j++) if ((A[j] & chk) == chk) cnt[i]++;
            }
            
            var X = 0L;
            for (int i = keta - 1; i >= 0; i--)
            {
                var chk = 1L;
                for (int j = 0; j < i; j++) chk <<= 1;
                if (cnt[i] <= N / 2)
                {
                    X += chk;
                    if (X > K) X -= chk;                    
                }
            }
            
            var ans = 0L;
            for (int i = 0; i < N; i++) ans += X ^ A[i];

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}