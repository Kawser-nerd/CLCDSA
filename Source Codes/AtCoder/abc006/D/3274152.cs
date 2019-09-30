using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_006
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var cs = new int[n];
            for (int i = 0; i < n; i++)
            {
                cs[i] = int.Parse(Console.ReadLine());
            }

            var dp = new List<int>();//?????????
            dp.Add(cs[0]);
            for (int i = 1; i < n; i++)
            {
                if (dp[dp.Count - 1] < cs[i])
                {
                    dp.Add(cs[i]);
                }
                else
                {
                    dp[BinarySearch(dp, cs[i]) + 1] = cs[i];
                }
            }

            /*for(int i = 0; i < dp.Count; i++)
            {
                Console.WriteLine(dp[i]);
            }*/

            Console.WriteLine(n - dp.Count);
        }

        static int BinarySearch(List<int> list, int value)
        {
            int bottom = -1;
            int top = list.Count;
            while (top - bottom > 1)
            {
                int x = (top + bottom) / 2;
                if (value <= list[x])
                {
                    top = x;
                }
                else
                {
                    bottom = x;
                }
            }
            return bottom;
        }
    }
}