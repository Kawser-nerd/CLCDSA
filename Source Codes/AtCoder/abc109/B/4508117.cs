using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        var s = Console.ReadLine();
        var c = s[s.Length - 1];
        var set = new HashSet<string> { s };

        for (int i = 1; i < n; i++)
        {
            s = Console.ReadLine();
            if (c != s[0] || !set.Add(s))
            {
                Console.WriteLine("No");
                return;
            }
            c = s[s.Length - 1];
        }

        Console.WriteLine("Yes");
    }
}