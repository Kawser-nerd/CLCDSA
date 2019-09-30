using System;
using System.IO;
using System.Diagnostics;
using System.Linq;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[] { 0 }.Concat(Console.ReadLine().Split().Select(int.Parse).ToArray()).Concat(new int[] { 0 }).ToArray();
        int sum = 0;
        for (int i = 1; i < a.Length; i++)
        {
            sum += Abs(a[i - 1] - a[i]);
        }
        for (int i = 1; i < a.Length - 1; i++)
        {
            Console.WriteLine(sum - (Abs(a[i - 1] - a[i]) + Abs(a[i + 1] - a[i])) + Abs(a[i + 1] - a[i - 1]));
        }
    }
}