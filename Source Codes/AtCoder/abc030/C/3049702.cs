using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_030
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            long n = long.Parse(input[0]);
            long m = long.Parse(input[1]);
            input = Console.ReadLine().Split(' ');
            long x = long.Parse(input[0]);
            long y = long.Parse(input[1]);
            var arrayA = new long[n];
            input = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                arrayA[i] = long.Parse(input[i]);
            }
            var arrayB = new long[m];
            input = Console.ReadLine().Split(' ');
            for (int i = 0; i < m; i++)
            {
                arrayB[i] = long.Parse(input[i]);
            }

            long t = 0;
            int aI = 0, bI = 0;
            int roundCnt = 0;
            for (; aI < n; aI++)
            {
                if (arrayA[aI] < t) continue;//??????

                t = arrayA[aI] + x;//?????
                //Console.WriteLine(t);
                for (; bI < m; bI++)
                {
                    if (arrayB[bI] < t) continue;

                    t = arrayB[bI] + y;
                    //Console.WriteLine(t);
                    roundCnt++;
                    break;
                }
            }

            Console.WriteLine(roundCnt);
        }
    }
}