using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_032
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
            long k = int.Parse(input[1]);
            var ss = new long[n];
            for (int i = 0; i < n; i++)
            {
                ss[i] = long.Parse(Console.ReadLine());
            }

            if (ss.Contains(0))
            {
                Console.WriteLine(n);
                return;
            }

            long mult = 1;
            int length = 0;
            int minIndex = 0;
            for(int i = 0; i < n; i++)
            {
                mult *= ss[i];
                while (mult > k && minIndex < i)
                {
                    mult /= ss[minIndex];
                    minIndex++;
                }
                if (mult <= k
                    && length < i - minIndex + 1)
                {
                    length = i - minIndex + 1;
                }
            }

            Console.WriteLine(length);
        }
    }
}