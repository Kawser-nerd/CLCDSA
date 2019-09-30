using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_007
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Read().Split(' ');
            long a = long.Parse(input[0]);
            long b = long.Parse(input[1]);
            var tenCnts = new long[19];
            for(int i = 0; i < 19; i++)
            {
                tenCnts[i] = TenForbiddenCnt(i);
                //Console.WriteLine(tenCnts[i]);
            }

            long result = ForbiddenCnt(b, tenCnts);
            //Console.WriteLine(result);
            long result2 = ForbiddenCnt(a - 1, tenCnts);
            //Console.WriteLine(result2);
            Console.WriteLine(result-result2);
        }

        static long ForbiddenCnt(long val,long[] tenCnts)
        {
            if (val < 10)
            {
                if (val == 9) return 2;
                if (val >= 4) return 1;
                else return 0;
            }
            else
            {
                long maxDigit = 1;
                long temp = val;
                while (temp >= 10)
                {
                    temp /= 10;
                    maxDigit++;
                }
                long divider = (long)Math.Pow(10, maxDigit - 1);
                long digitNum = val / divider;
                long cnt = 0;
                if (digitNum < 4)
                {
                    cnt += tenCnts[maxDigit-1] * digitNum;
                    cnt += ForbiddenCnt(val - divider * digitNum, tenCnts);
                }
                else if (digitNum == 4)
                {
                    cnt += tenCnts[maxDigit-1] * 4;
                    cnt += val - divider * digitNum + 1;
                }
                else if (digitNum < 9)
                {
                    cnt += tenCnts[maxDigit-1] * (digitNum - 1);
                    cnt += divider;
                    cnt += ForbiddenCnt(val - divider * digitNum, tenCnts);
                }
                else if (digitNum == 9)
                {
                    cnt += tenCnts[maxDigit-1] * 8;
                    cnt += divider;
                    cnt += val - divider * digitNum + 1;
                }
                /*for(int i = 1; i <= digitNum; i++)
                {
                    if (i == 5)
                    {
                        cnt += divider;
                    }
                    else
                    {
                        cnt += tenCnts[maxDigit - 1];
                    }
                }
                cnt += ForbiddenCnt(val % divider, tenCnts);*/
                return cnt;
            }
        }

        static long TenForbiddenCnt(int pow)
        {
            if (pow == 0)
            {
                return 0;
            }
            else if (pow == 1)
            {
                return 2;
            }
            else
            {
                long cnt = 0;
                cnt += TenForbiddenCnt(pow - 1) * 8;
                cnt += (long)Math.Pow(10, pow - 1) * 2;
                return cnt;
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