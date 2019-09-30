using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

        int[] h = new int[n];
        h[1] = Math.Abs(a[1] - a[0]);

        for (int i = 2; i < n; i++)
        {
            h[i] = Math.Min(h[i - 1] + Math.Abs(a[i - 1] - a[i]), h[i - 2] + Math.Abs(a[i - 2] - a[i]));
        }
        Console.WriteLine(h[n - 1]);
    }
}