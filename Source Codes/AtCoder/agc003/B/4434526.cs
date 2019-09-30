using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        long res = 0;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            int now = int.Parse(Console.ReadLine());
            int use = Min(last, now);
            res += use;
            now -= use;
            res += now / 2;
            now %= 2;
            last = now;
        }
        res += last / 2;
        Console.WriteLine(res);
    }
}