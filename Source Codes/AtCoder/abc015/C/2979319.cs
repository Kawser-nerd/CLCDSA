using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_014
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
            var choices = new int[n, k];
            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split(' ');
                for(int j = 0; j < k; j++)
                {
                    choices[i, j] = int.Parse(input[j]);
                }
            }

            int allPat = (int)Math.Pow(k, n);

            for(int i = 0; i < allPat; i++)
            {
                int val = 0;
                for(int j = 0; j < n; j++)
                {
                    if (j == 0)
                    {
                        val= choices[j, (i / (int)Math.Pow(k, j)) % k];
                    }
                    else
                    {
                        val ^= choices[j, (i / (int)Math.Pow(k, j)) % k];
                    }
                }
                if (val == 0)
                {
                    Console.WriteLine("Found");
                    return;
                }
            }
            Console.WriteLine("Nothing");
        }
    }
}