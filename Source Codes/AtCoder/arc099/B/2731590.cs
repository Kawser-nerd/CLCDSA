using System;
using System.Collections.Generic;

namespace ARC099D
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int k = int.Parse(Console.ReadLine());

            long max = (long) Math.Pow(10, 15);
            Dictionary<long, double> rates = new Dictionary<long, double>();
            for (long i = 1; i < max;)
            {
                rates.Add(i, Rate(i));
                i += Math.Max((long) Math.Pow(10, Digit(i + 1) - 4), 1);
            }

            List<long> keyList = new List<long>(rates.Keys);
            keyList.Reverse();
            double min = max;

            List<long> ans = new List<long>();
            foreach (long index in keyList)
            {
                if (min >= rates[index])
                {
                    ans.Add(index);
                    min = rates[index];
                }
            }

            ans.Reverse();
            for (int i = 0; i < k; i++)
            {
                Console.WriteLine(ans[i]);
            }
        }

        public static int Digit(long n)
        {
            return n == 0 ? 1 : (int) Math.Log10(n) + 1;
        }

        public static double Rate(long n)
        {
            long temp = n;
            long sn = 0;
            while (temp > 0)
            {
                sn += temp % 10;
                temp /= 10;
            }

            return (double) n / sn;
        }
    }
}