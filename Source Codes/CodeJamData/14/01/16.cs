using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    int Solve(int firstAnswer, int[][] firstCards, int secondAnswer, int[][] secondCards)
    {
        var result = firstCards[firstAnswer - 1].Intersect(secondCards[secondAnswer - 1]).ToArray();
        return result.Length == 1 ? result[0] : -result.Length;
    }

    static IEnumerable<string> Output()
    {
        var lines = Enumerable.Range(0, 10).Select(i => Console.ReadLine().Split(' ').Select(int.Parse).ToArray()).ToArray();
        var result = new B().Solve(lines[0][0], lines.Skip(1).Take(4).ToArray(), lines[5][0], lines.Skip(6).Take(4).ToArray());
        yield return result < 0 ? "Bad magician!" : result == 0 ? "Volunteer cheated!" : result.ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}