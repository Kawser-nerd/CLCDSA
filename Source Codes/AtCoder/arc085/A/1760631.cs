using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        long n = vals[0];
        long m = vals[1];

        long time = m * 1900 + (n - m) * 100;

        double sum = 0;
        double okRate = 1 / Math.Pow(2, m);
        double curRate = 1;
        for (int i = 1; true; i++)
        {
            var curTime = time * i * curRate * okRate;

            if (curTime < 0.01)
            {
                break;
            }
            sum += curTime;
            curRate = curRate * (1 - okRate);
        }

        Console.WriteLine(Math.Round(sum));
    }
}