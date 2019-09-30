using System.Linq;
using System;
class A
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = int.Parse(Console.ReadLine());
        }
        Console.WriteLine(a.Sum());
        Array.Sort(a);
        Array.Reverse(a);
        if (a.Length == 1) { Console.WriteLine(a[0]);return; }
        if (a[0] <= a.Sum() - a[0]) { Console.WriteLine(0); }
        else { Console.WriteLine(Math.Abs(a[0] * 2 - a.Sum())); }
        Console.ReadLine();
    }
}