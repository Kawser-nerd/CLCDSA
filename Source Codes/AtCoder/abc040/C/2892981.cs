using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ABC_040
{
    class C
    {
        static Stack<int> posStack;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            var array = new int[n];
            var minCost = new long[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = int.Parse(input[i]);
                minCost[i] = 0;
            }

            for(int i = n - 1; i >= 0; i--)
            {
                //???????????
                if (i == n - 1)
                {
                    minCost[i] = 0;
                }
                else if (i == n - 2)
                {
                    minCost[i] = Math.Abs(array[i] - array[i + 1]);
                }
                else
                {
                    long cost1 = Math.Abs(array[i] - array[i + 1]) + minCost[i + 1];
                    long cost2 = Math.Abs(array[i] - array[i + 2]) + minCost[i + 2];
                    minCost[i] = cost1 < cost2 ? cost1 : cost2;
                }
            }

            Console.WriteLine(minCost[0]);
        }
    }
}