using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    List<int> Solve(List<List<int>> map)
    {
        return map.SelectMany(m => m).GroupBy(m => m).Where(g => g.Count() % 2 > 0).Select(g => g.Key).OrderBy(m => m).ToList();
    }

    static IEnumerable<string> Output()
    {
        var map = Enumerable.Range(0, int.Parse(Console.ReadLine()) * 2 - 1).Select(i => Console.ReadLine().Split(' ').Select(int.Parse).ToList()).ToList();
        yield return string.Join(" ", new B().Solve(map));
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}