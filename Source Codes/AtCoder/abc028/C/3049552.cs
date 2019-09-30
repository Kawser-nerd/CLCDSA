using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_028
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            var vals = new int[5];
            for (int i = 0; i < 5; i++)
            {
                vals[i] = int.Parse(input[i]);
            }

            var sums = new List<int>();
            for(int i = 0; i < 3; i++)
            {
                for(int j = i + 1; j < 4; j++)
                {
                    for(int k = j + 1; k < 5; k++)
                    {
                        sums.Add(vals[i] + vals[j] + vals[k]);
                    }
                }
            }

            sums.Sort();
            int val = 0;
            int variousCnt = 0;
            for(int i = sums.Count - 1; i >= 0; i--)
            {
                if (val != sums[i])
                {
                    variousCnt++;
                    if (variousCnt == 3)
                    {
                        Console.WriteLine(sums[i]);
                        return;
                    }
                }
            }
        }
    }
}