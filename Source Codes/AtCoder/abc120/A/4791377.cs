using System;
using System.Linq;

class Problem
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int ans = Math.Min(a[1] / a[0], a[2]);
        Console.WriteLine(ans);
    }
}