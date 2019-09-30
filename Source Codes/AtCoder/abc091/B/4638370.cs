using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var dict = new Dictionary<string, int>();

        var n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine();
            if (dict.ContainsKey(s))
            {
                dict[s]++;
            }
            else
            {
                dict[s] = 1;
            }
        }

        var m = int.Parse(Console.ReadLine());
        for (int i = 0; i < m; i++)
        {
            var s = Console.ReadLine();
            if (dict.ContainsKey(s))
            {
                dict[s]--;
            }
        }

        var max = 0;
        foreach (var item in dict)
        {
            max = Math.Max(max, item.Value);
        }

        Console.WriteLine(max);
    }
}