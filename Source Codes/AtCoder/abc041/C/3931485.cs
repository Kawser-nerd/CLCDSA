using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();

        Dictionary<int, int> keyValuePairs = new Dictionary<int, int>();
        for (int i = 1; i <= n; i++)
        {
            keyValuePairs.Add(i, a[i - 1]);
        }
        var ranking = keyValuePairs.OrderByDescending(i => i.Value);
        var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        Console.SetOut(sw);
        foreach (var item in ranking)
        {
            Console.WriteLine(item.Key);
        }
        Console.Out.Flush();
    }
}