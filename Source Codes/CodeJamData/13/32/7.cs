using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    public string Solve(int x, int y)
    {
        return string.Join("", Enumerable.Repeat(x > 0 ? "WE" : "EW", Math.Abs(x)).ToArray())+
            string.Join("", Enumerable.Repeat(y > 0 ? "SN" : "NS", Math.Abs(y)).ToArray());
    }

    static IEnumerable<string> Output() {
        var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new B().Solve(line[0], line[1]); 
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}

