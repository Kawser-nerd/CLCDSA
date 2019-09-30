using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var v = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        int count = 0;

        while (v[0] != v[1] || v[1] != v[2] || v[2] != v[0])
        {
            Array.Sort(v, (a, b) => a.CompareTo(b));
            if (v[0] == v[1])
            {
                v[0]++;
                v[1]++;
            }
            else
            {
                v[0] += 2;
            }

            count++;
        }

        Console.WriteLine(count);
    }
}