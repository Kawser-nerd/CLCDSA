using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    string Solve(string S)
    {
        var ret = new List<char>();
        foreach (var c in S)
        {
            if (ret.Count > 0 && c >= ret[0]) ret.Insert(0, c);
            else ret.Add(c);
        }
        return new string(ret.ToArray());
    }

    static IEnumerable<string> Output()
    {
        yield return new A().Solve(Console.ReadLine());
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}