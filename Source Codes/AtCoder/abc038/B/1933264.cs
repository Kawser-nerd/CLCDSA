using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int a = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1] ? "YES" : "NO");
    }
}