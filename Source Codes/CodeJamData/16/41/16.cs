using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    string Solve(int N, int R, int P, int S)
    {
        var str = new string[] { "R", "P", "S" };
        Func<string, string, string> concat = (x, y) => x.CompareTo(y) < 0 ? x + y: y + x;
        for (int i = 0; i < N; i++) str = new string[] { concat(str[0], str[2]), concat(str[1], str[0]), concat(str[2], str[1]) };
        foreach (var s in str) if (s.Count(ss => ss == 'R') == R && s.Count(ss => ss == 'P') == P && s.Count(ss => ss == 'S') == S) return s;
        return null;        
    }

    static void Output()
    {
        var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        Console.WriteLine(new A().Solve(line[0], line[1], line[2], line[3]) ?? "IMPOSSIBLE");
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) { Console.Write("Case #{0}: ", i); Output(); } }
}