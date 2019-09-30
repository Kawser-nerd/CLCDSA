using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_035
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
            int q = int.Parse(input[1]);
            var sums = new int[n];
            for (int i = 0; i < q; i++)
            {
                input = Console.ReadLine().Split(' ');
                sums[int.Parse(input[0]) - 1]++;
                if (int.Parse(input[1]) < n)
                {
                    sums[int.Parse(input[1])]--;
                }
            }

            //Console.WriteLine(sums[0]);
            //string s = sums[0] % 2 == 0 ? "0" : "1";
            Console.Write(sums[0] % 2);
            for (int i = 1; i < n; i++)
            {
                sums[i] += sums[i - 1];
                //s += sums[i] % 2 == 0 ? "0" : "1";
                Console.Write(sums[i] % 2);
            }
            Console.WriteLine();
        }
    }
}