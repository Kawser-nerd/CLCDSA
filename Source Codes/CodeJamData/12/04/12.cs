using System;
using System.Collections.Generic;
using System.Linq;

class D
{
    public int Solve(int D, string[] layout)
    {
        int h = layout.Length - 2;
        int w = layout[0].Length - 2;
        int dy = layout.TakeWhile(lay => !lay.Contains('X')).Count() - 1;
        int dx = layout[dy + 1].IndexOf('X') - 1;

        var query = Enumerable.Range(-D / h - 1, 2 * D / h + 3)
            .Select(yy => yy * h + (yy % 2 == 0 ? 0 : (2 * dy + 1 - h)))
            .Where(y => y != 0)
            .SelectMany(y =>
                Enumerable.Range(-D / w - 1, 2 * D / w + 3)
                .Select(xx => new { x = xx * w + (xx % 2 == 0 ? 0 : 2 * dx + 1 - w), y = y }))
            .Where(p => p.x * p.x + p.y * p.y <= D * D)
            .Select(p => Tuple.Create(p.y > 0, Math.Round((double)p.x / p.y, 8)))
            .Distinct();
        return query.Count() + (1 + 2 * dx <= D ? 1 : 0) + (1 + 2 * (w - 1 - dx) <= D ? 1 : 0);
    }


    static IEnumerable<string> Output()
    {
        var inputs = Console.ReadLine().Split().Select(s => Convert.ToInt32(s)).ToArray();
        yield return new D().Solve(inputs[2], new int[inputs[0]].Select(i=>Console.ReadLine()).ToArray()).ToString();
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.Write(Output().Aggregate(string.Format("Case #{0}: ", i), (a, b) => a + b + Environment.NewLine));
    }
}