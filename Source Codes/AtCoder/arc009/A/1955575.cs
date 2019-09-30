using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int money = 0;
        for (int i = 0; i < n; i++)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            money += a[0] * a[1];
        }
        Console.WriteLine((int)Math.Floor(money * 1.05));
    }
}