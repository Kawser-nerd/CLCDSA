using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    public int Solve(int S, int P, int[] points)
    {
        var pred =
            P == 0 ? new Func<int, bool>(point => true) :
            P == 1 ? new Func<int, bool>(point => point >= 1) :
            new Func<int, bool>(point => point >= P * 3 - 2 || (S-- > 0 && point >= P * 3 - 4));
        return points.OrderByDescending(point => point).Count(pred);
    }

    static IEnumerable<string> Output()
    {
        var inputs = Console.ReadLine().Split().Select(s => Convert.ToInt32(s)).ToArray();
        yield return new B().Solve(inputs[1], inputs[2], inputs.Skip(3).ToArray()).ToString();
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.Write(Output().Aggregate(string.Format("Case #{0}: ", i), (a, b) => a + b + Environment.NewLine));
    }
}