using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;
class P
{
    static void Main()
    {
        char[] c = Console.ReadLine().ToArray();
        long res = 0;
        for (int i = 0; i < c.Length; i++)
        {
            if (c[i] == 'U')
            {
                res += i * 2 + c.Length - (1 + i);
            }
            else
            {
                res += i + (c.Length - (1 + i)) * 2;
            }
        }
        Console.WriteLine(res);
    }
}