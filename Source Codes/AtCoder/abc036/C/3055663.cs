using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_036
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var array = new long[n];
            var sortArray = new long[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = long.Parse(Console.ReadLine());
                sortArray[i] = array[i];
            }
            var rankDict = new Dictionary<long, int>();
            Array.Sort(sortArray);
            long nowVal = -1;
            int nowCnt = 0;
            for(int i = 0; i < n; i++)
            {
                if (nowVal == sortArray[i]) continue;

                rankDict.Add(sortArray[i], nowCnt);
                nowVal = sortArray[i];
                nowCnt++;
            }
            for(int i = 0; i < n; i++)
            {
                Console.WriteLine(rankDict[array[i]]);
            }
        }
    }
}