using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int min = int.MaxValue;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ij = i * j;
                if (ij > n)
                {
                    break;
                }
                min = Math.Min(min, (n - ij) + Math.Abs(i - j));
            }
        }
        Console.WriteLine(min);
    }
}