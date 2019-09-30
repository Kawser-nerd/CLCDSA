using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_030
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] na = ReadInts();
            int n = na[0];
            int a = na[1];
            string k = Read();
            int[] bs = ReadInts();
            //find loop
            var visitDict = new Dictionary<int, int>();
            int now = a - 1;
            int cnt = 0;
            do
            {
                visitDict.Add(now, cnt);
                cnt++;
                now = bs[now] - 1;
            }
            while (!visitDict.ContainsKey(now));
            int beforeLoopSize = visitDict[now];
            int loopSize = cnt - visitDict[now];
            int mod = 0;
            for (int i = 0; i < k.Length; i++)
            {
                mod = (mod * 10 + (k[i] - '0')) % loopSize;
            }

            int mm = mod;
            if (beforeLoopSize - mm > 0)
            {
                int div = (beforeLoopSize - mm) / loopSize;
                if ((beforeLoopSize - mm) % loopSize > 0) div++;
                mm += div * loopSize;
            }
            int val = mm;
            if (k.Length < 7)
            {
                int kk = int.Parse(k);
                if (kk < mm + beforeLoopSize)
                {
                    val = kk;
                }
            }
            now = a - 1;
            while (val > 0)
            {
                now = bs[now] - 1;
                val--;
            }
            Console.WriteLine(now + 1);
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