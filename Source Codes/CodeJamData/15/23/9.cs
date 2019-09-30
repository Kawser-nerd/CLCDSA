using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    int Solve(long[][] DHM)
    {
        if (DHM.Length == 1) return 0;
        var times = DHM.Select(dhm =>
        {
            var time1 = (360 - dhm[0]) * dhm[2];
            return Tuple.Create(time1, time1 + 360 * dhm[2]);
        }).ToArray();
        return times[0].Item2 <= times[1].Item1 || times[1].Item2 <= times[0].Item1 ? 1 : 0; 
    }

    static IEnumerable<string> Output()
    {
        var N = int.Parse(Console.ReadLine());
        yield return new C().Solve(Enumerable.Range(0, N).Select(r => Console.ReadLine().Split(' ').Select(long.Parse).ToArray()).ToArray()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}