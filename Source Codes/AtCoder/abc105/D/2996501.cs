using System;
using System.Collections.Generic;

namespace AtTest.ABC_105
{
    class D
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
            input = Console.ReadLine().Split(' ');
            var array = new int[n];
            var sums = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = int.Parse(input[i]) % m;
                if (i == 0)
                {
                    sums[i] = array[i] % m;
                }
                else
                {
                    sums[i] = (sums[i - 1] + array[i]) % m;
                }
            }

            var marginDict = new Dictionary<int, int>();
            marginDict.Add(0, 1);
            long cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if (marginDict.ContainsKey(sums[i]))
                {
                    cnt += marginDict[sums[i]];
                    marginDict[sums[i]]++;
                }
                else
                {
                    marginDict.Add(sums[i], 1);
                }
            }

            Console.WriteLine(cnt);
        }
    }
}