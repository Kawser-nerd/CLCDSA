using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] hm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        int m = int.Parse(Console.ReadLine());

        Console.WriteLine(n / m >= 2 ? "YES" : "NO");

    }
}