using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using System.Collections;

class P
{
    static void Main()
    {
        var nk = Console.ReadLine().Split().Select(int.Parse).ToList();
        var a = Console.ReadLine().Split().Select(int.Parse).ToList();
        for (int i = 1; i < a.Count; i++)
        {
            if(a[i - 1] + a[i] >= nk[1])
            {
                Console.WriteLine("Possible");
                for (int j = a.Count - 1; j > i; j--) Console.WriteLine(j);
                for (int j = 1; j < i; j++) Console.WriteLine(j);
                Console.WriteLine(i);
                return;
            }
        }
        Console.WriteLine("Impossible");
    }
}