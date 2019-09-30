using System;
using System.Collections.Generic;

namespace AtTest.D_Challenge
{
    class ABC_001
    {
        static void Main(string[] args)
        {
            Method(args);
            //Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var rainSpan = new int[n][];
            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split('-');
                var rain = new int[2];
                rain[0] = int.Parse(input[0]);
                rain[1] = int.Parse(input[1]);
                if (rain[0] % 5 > 0) rain[0] -= rain[0] % 5;
                if (rain[1] % 5 > 0)
                {
                    rain[1] += 5 - rain[1] % 5;
                    if (rain[1] % 100 == 60)
                    {
                        rain[1] += 40;
                    }
                }
                rainSpan[i] = rain;
            }
            Array.Sort(rainSpan, (a, b) => a[0]-b[0]);
            /*for (int i = 0; i < n; i++)
            {
                Console.Write(rainSpan[i][0]);
                Console.Write("-");
                Console.WriteLine(rainSpan[i][1]);
            }*/
            int startTime = rainSpan[0][0];
            int endTime = rainSpan[0][1];
            var rainList = new List<int[]>();
            for (int i = 1; i <= n; i++)
            {
                if (i == n || rainSpan[i][0] > endTime)
                {
                    rainList.Add(new int[2]
                    {
                        startTime, endTime
                    });
                    if (i < n)
                    {
                        startTime = rainSpan[i][0];
                        endTime = rainSpan[i][1];
                    }
                }
                else if(endTime<rainSpan[i][1])
                {
                    endTime = rainSpan[i][1];
                }
            }
            for(int i = 0; i < rainList.Count; i++)
            {
                Console.Write(rainList[i][0].ToString("d4"));
                Console.Write("-");
                Console.WriteLine(rainList[i][1].ToString("d4"));
            }
        }
    }
}