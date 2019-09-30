using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var set = new HashSet<char>();
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            set.Add(s[i][0]);
        }
        Console.WriteLine(set.Count == 3 ? "Three" : "Four");
    }
}