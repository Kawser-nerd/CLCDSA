using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long l1 = 2;
        long l2 = 1;
        for (int i = 2; i <= n; i++)
        {
            long next = l1 + l2;
            l1 = l2;
            l2 = next;
        }
        Console.WriteLine(l2);
    }
}