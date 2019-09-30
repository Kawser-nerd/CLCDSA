using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var ws = new string[n];
        for (int i = 0; i < ws.Length; i++)
        {
            ws[i] = Console.ReadLine().Trim();
        }

        var set = new HashSet<string>(ws);
        if (set.Count < ws.Length)
        {
            Console.WriteLine("No");
            return;
        }

        for (int i = 1; i < ws.Length; i++)
        {
            if (ws[i - 1].Last() != ws[i].First())
            {
                Console.WriteLine("No");
                return;
            }
        }
        Console.WriteLine("Yes");
    }
}