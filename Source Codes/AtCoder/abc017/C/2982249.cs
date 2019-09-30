using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_017
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            var ls = new int[n];
            var rs = new int[n];
            var ss = new long[n];
            long allScore = 0;
            var sums = new long[m];
            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split(' ');
                ls[i] = int.Parse(input[0]) - 1;
                rs[i] = int.Parse(input[1]) - 1;
                ss[i] = long.Parse(input[2]);
                allScore += ss[i];
                sums[ls[i]] += ss[i];
                if (rs[i] < m - 1)
                {
                    sums[rs[i] + 1] -= ss[i];
                }
            }

            for(int i = 1; i < m; i++)
            {
                sums[i] += sums[i - 1];
            }


            Console.WriteLine(allScore - sums.Min());
        }
    }
}