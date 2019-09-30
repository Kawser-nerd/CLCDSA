using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();

        Dictionary<int, int> keyValuePairs = new Dictionary<int, int>();
        for (int i = 1; i <= n; i++)
        {
            keyValuePairs.Add(i, a[i-1]);
        }
        var ranking = keyValuePairs.OrderByDescending(i => i.Value);
        foreach (var item in ranking)
        {
            Console.WriteLine(item.Key);
        }
    }
}