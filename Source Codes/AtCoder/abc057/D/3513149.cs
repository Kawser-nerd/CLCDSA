using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_057
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nab = ReadInts();
            long[] vs = ReadLongs();
            vs = vs.OrderBy(a => -a).ToArray();
            var sameCnt = new List<long[]>();
            sameCnt.Add(new long[2] { vs[0], 1 });
            for(int i = 1; i < nab[0]; i++)
            {
                if (sameCnt[sameCnt.Count - 1][0] != vs[i])
                {
                    sameCnt.Add(new long[2] { vs[i], 1 });
                }
                else
                {
                    sameCnt[sameCnt.Count - 1][1]++;
                }
            }
            double ave=0;
            long cnt=0;
            if (sameCnt[0][1] < nab[1])
            {
                int remain = nab[1];
                long sum = 0;
                for (int i = 0; i < sameCnt.Count; i++)
                {
                    if (remain <= sameCnt[i][1])
                    {
                        cnt = Combination(sameCnt[i][1], remain);
                        sum += sameCnt[i][0] * remain;
                        ave = 1.0 * sum / nab[1];
                        break;
                    }
                    else
                    {
                        sum += sameCnt[i][0] * sameCnt[i][1];
                        remain -= (int)sameCnt[i][1];
                    }
                }
            }
            else
            {
                ave = sameCnt[0][0];
                for(int i = nab[1]; i <= nab[2]; i++)
                {
                    if (sameCnt[0][1] < i) break;
                    cnt += Combination(sameCnt[0][1], i);

                }
            }
            Console.WriteLine(ave);
            Console.WriteLine(cnt);
        }

        static long Combination(long m,long n)
        {
            if (m - n < n) n = m - n;
            long res = 1;
            var dividers = new List<long>();
            for(long i = 2; i <= n; i++)
            {
                dividers.Add(i);
            }
            for (long i = m - n + 1; i <= m; i++)
            {
                res *= i;
                for(int j = 0; j < dividers.Count; j++)
                {
                    if (res % dividers[j] == 0)
                    {
                        res /= dividers[j];
                        dividers.RemoveAt(j);
                        j--;
                    }
                }
            }
            return res;
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