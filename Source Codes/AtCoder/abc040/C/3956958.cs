using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();

        int[] cost = new int[n];

        cost[0] = 0;
        cost[1] = Math.Abs(a[1] - a[0]);

        for (int i = 2; i < n; i++)
        {
            cost[i] = Math.Min(cost[i - 2] + Math.Abs(a[i] - a[i - 2]), cost[i - 1] + Math.Abs(a[i] - a[i - 1]));
        }

        Console.WriteLine(cost[n - 1]);
    }
}