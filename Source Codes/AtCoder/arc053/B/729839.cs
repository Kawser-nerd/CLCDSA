using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main (string[] args)
    {
        var s = Console.ReadLine();

        var dict = new Dictionary<char, int>();

        foreach (var c in s)
        {
            if (dict.ContainsKey(c))
            {
                dict[c]++;
            }
            else
            {
                dict.Add(c, 1);
            }
        }

        var count1 = 0;
        var count2 = 0;

        foreach (var item in dict)
        {
            count1 += item.Value % 2;
            count2 += item.Value / 2;
        }

        if (count1 == 0)
        {
            Console.WriteLine(s.Length);
        }
        else
        {
            Console.WriteLine((count2 / count1) * 2 + 1);
        }

    }
}