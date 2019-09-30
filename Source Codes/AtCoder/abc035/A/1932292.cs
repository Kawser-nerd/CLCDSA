using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine((a[0] * 3 == a[1] * 4 ? "4:3" : "16:9"));
    }
}