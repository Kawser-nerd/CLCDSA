using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_037
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
            int k = int.Parse(input[1]);
            var array = new long[n];
            var sums = new long[n];
            input = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                array[i] = long.Parse(input[i]);
                sums[i] = i == 0 ? array[i] : array[i] + sums[i - 1];
            }
            long result = 0;
            for(int i = k - 1; i < n; i++)
            {
                result += i == k - 1 ? sums[i] : sums[i] - sums[i - k];
            }
            Console.WriteLine(result);
        }
    }
}