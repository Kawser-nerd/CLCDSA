using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = int.Parse(Console.ReadLine());
        }

        long ope = 0;
        var right = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > i)
            {
                ope = -1;
                break;
            }

            if(a[i] + 1 < right)
            {
                ope = -1;
                break;
            }

            if (a[i] + 1 != right)
            {
                ope += a[i];
            }
            right = a[i];
        }

        Console.WriteLine(ope);
    }
}