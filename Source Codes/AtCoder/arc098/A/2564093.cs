using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine();
        var toWest = new int[n];
        var toEest = new int[n];

        int west = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'W')
            {
                west++;
            }
            toWest[i] = west;
        }
        int east = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'E')
            {
                east++;
            }
            toEest[i] = east;
        }
        var min = int.MaxValue;
        for (int i = 0; i < n; i++)
        {
            int x = 0;
            if (i > 0)
            {
                x += toWest[i - 1];
            }
            if (i < n - 1)
            {
                x += toEest[i + 1];
            }
            min = Math.Min(min, x);
        }

        Console.WriteLine(min);
    }
}