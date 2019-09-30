using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

        long pattern = 0;
        long sum = 0;
        for (int i = 0, j = 0; i < n && j < n;)
        {
            while ((sum ^ a[j]) != (sum + a[j]))
            {
                sum ^= a[i];
                i++;
            }
            int x = j - i + 1;
            pattern += x;
            sum ^= a[j];
            j++;
        }

        Console.WriteLine(pattern);
    }
}