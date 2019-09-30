using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] rcd = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int d = rcd[2];
        int res = 0;
        for (int i = 0; i < rcd[0]; i++)
        {
            int[] tako = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 0; j < tako.Length; j++)
            {
                if ((i + j) % 2 == d % 2 && i + j <= d) res = Math.Max(res, tako[j]);
            }
        }
        Console.WriteLine(res);

    }
}