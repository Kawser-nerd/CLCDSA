using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        var dict = new Dictionary<int, int>();
        for (int i = 0; i < n; i++)
        {
            var x = int.Parse(Console.ReadLine());
            if (dict.ContainsKey(x))
            {
                dict[x]++;
            }
            else
            {
                dict[x] = 1;
            }
        }

        var ans = 0;
        foreach (var item in dict)
        {
            if (item.Value % 2 == 1)
            {
                ans++;
            }
        }

        Console.WriteLine(ans);
    }
}