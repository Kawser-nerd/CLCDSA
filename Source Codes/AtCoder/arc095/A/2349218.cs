using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var x = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var sorted = x.OrderBy(i => i).ToArray();

        var answer = new StringBuilder();
        for (int i = 0; i < n; i++)
        {
            var mean = sorted[n / 2];
            if (x[i] < mean)
            {
                answer.AppendLine(mean.ToString());
            }
            else
            {
                answer.AppendLine(sorted[n / 2 - 1].ToString());
            }

        }

        Console.Write(answer);
    }
}