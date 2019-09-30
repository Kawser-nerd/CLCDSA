using System;
using System.Collections.Generic;
using System.Linq;

class Program
{

    static void Main(string[] args)
    {
        var map = new Dictionary<char, int>
        {
            {'A', 4},
            {'B', 3},
            {'C', 2},
            {'D', 1},
            {'F', 0},
        };

        var N = int.Parse(Console.ReadLine());
        var scores = new List<int>();
        foreach (var c in Console.ReadLine())
        {
            scores.Add(map[c]);
        }

        Console.WriteLine(scores.Average());
    }
}