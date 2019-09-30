using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int[] hm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        int[] a = Enumerable.Range(1, n).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        int res = 0;
        switch (n)
        {
            case 1:
            res = a.Max();
            break;
            case 2:
            res = a.Max();
            break;
            case 3:
            res = new int[] {Math.Max(a[0], a[1]+ a[2]), Math.Max(a[1], a[0] + a[2]), Math.Max(a[2], a[0] + a[1]) }.Min();
            break;
            case 4:
            res = new int[] { Math.Max(a[0], a[1] + a[2] + a[3]), Math.Max(a[1], a[0] + a[2] + a[3]), Math.Max(a[2], a[1] + a[0] + a[3]), Math.Max(a[3], a[1] + a[2] + a[0]), Math.Max(a[0] + a[1],  a[2] + a[3]), Math.Max(a[0] + a[2], a[1] + a[3]), Math.Max(a[0] + a[3], a[2] + a[1]) }.Min();
            break;
        }
        Console.WriteLine(res);
    }
}