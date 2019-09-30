using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = int.Parse(Console.ReadLine());
        }

        var set = new HashSet<int>();
        var x = 1;
        var k = 0;
        while (set.Add(x))
        {
            if (x == 2)
            {
                Console.WriteLine(k);
                return;
            }
            x = a[x - 1];
            k++;
        }
        Console.WriteLine(-1);
    }
}