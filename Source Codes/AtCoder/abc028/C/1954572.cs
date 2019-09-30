using System;
using System.Linq;
using System.Collections.Generic;
 
class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(new int[] { a[0] + a[1] + a[2], a[0] + a[1] + a[3], a[0] + a[1] + a[4], a[0] + a[2] + a[3], a[0] + a[2] + a[4], a[0] + a[3] + a[4], a[1] + a[2] + a[3], a[1] + a[2] + a[4], a[1] + a[3] + a[4], a[2] + a[3] + a[4] }.Distinct().OrderByDescending(x => x).ElementAt(2));
    }
}