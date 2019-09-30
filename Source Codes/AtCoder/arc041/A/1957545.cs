using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int a = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        Console.WriteLine(n[0] + Math.Min(n[1],a) - Math.Max(a - n[1],0));
    }
}