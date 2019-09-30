using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_008
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
            var array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = int.Parse(Console.ReadLine());
            }

            double expectValue = 0;
            for(int i=0; i < n; i++)
            {
                int divisorCnt = 0;
                for(int j = 0; j < n; j++)
                {
                    if (array[i] % array[j] == 0)//????
                    {
                        divisorCnt++;
                    }
                }

                if (divisorCnt % 2 == 0)
                {
                    expectValue += 0.5;
                }
                else
                {
                    expectValue += 1.0 * (divisorCnt + 1) / (2 * divisorCnt);
                }
            }

            Console.WriteLine(expectValue);
        }
    }
}