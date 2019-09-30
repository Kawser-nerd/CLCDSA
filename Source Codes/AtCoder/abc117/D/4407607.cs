using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            long N = long.Parse(s[0]);
            long K = long.Parse(s[1]);
            long[] A = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).OrderByDescending(x => x).ToArray();
            int len = Convert.ToString(Math.Max(K, A[0]), 2).Length;
            string Kstr = Convert.ToString(K, 2).PadLeft(len, '0');
            string[] Astr = A.Select(x => Convert.ToString(x, 2).PadLeft(len, '0')).ToArray();
            long[] nums = new long[len];
            foreach (string a in Astr)
            {
                for (int i = 0; i < len; i++)
                {
                    if (a[i] == '0') { nums[i]++; }
                }
            }
            long res = 0;
            for (int i = 0; i < len; i++)
            {
                long restemp = 0;
                long temp = 1;
                
                if (Kstr[i] == '1')
                {
                    for (int j = len - 1; j > i; j--)
                    {
                        if (N - nums[j] < nums[j]) { restemp += temp * nums[j]; }
                        else { restemp += temp * (N - nums[j]); }
                        temp *= 2;
                    }
                    restemp += temp * (N - nums[i]);
                    temp *= 2;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (Kstr[j] == '0') { restemp += temp * (N - nums[j]); }
                        else { restemp += temp * nums[j]; }
                        temp *= 2;
                    }
                }
                else
                {
                    for (int j = len - 1; j >= 0; j--)
                    {
                        if (Kstr[j] == '0') { restemp += temp * (N - nums[j]); }
                        else { restemp += temp * nums[j]; }
                        temp *= 2;
                    }
                }
                
                res = Math.Max(restemp, res);
            }
            Console.WriteLine("{0}", res);
        }
    }
}