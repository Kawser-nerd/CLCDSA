using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(int.Parse).Distinct().ToArray();
        Console.WriteLine(a.Length - ((n - a.Length) % 2 == 0 ? 0 : 1));
    }
}