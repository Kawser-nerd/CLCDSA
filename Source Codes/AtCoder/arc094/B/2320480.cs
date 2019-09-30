using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var anwer = new StringBuilder();
        for (int i = 0; i < n; i++)
        {
            var q = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var score = q[0] * q[1] - 1;
            var r = (long)(Math.Sqrt(score)) + 1;
            while (r > 0 && r * r > score)
            {
                r--;
            }

            long count = r * 2 - q.Distinct().Count(qq => qq <= r);
            if (r != 0 && score / r == r)
            {
                count--;
            }
            anwer.AppendLine(count.ToString());
        }

        Console.Write(anwer.ToString());
    }
}