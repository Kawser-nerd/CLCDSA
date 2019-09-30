using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    public int Solve(int A, int B)
    {
        return Enumerable.Range(A, B - A + 1).AsParallel().Sum(i =>{
            var s = i.ToString();
            return Enumerable.Range(1, s.Length - 1)
                .Select(j => s.Substring(s.Length - j, j) + s.Substring(0, s.Length - j))
                .Select(ss=>Convert.ToInt32(ss))
                .Distinct().Count(j => i < j && j <= B);
        });
    }

    static IEnumerable<string> Output()
    {
        var inputs = Console.ReadLine().Split().Select(s => Convert.ToInt32(s)).ToArray();
        yield return new C().Solve(inputs[0], inputs[1]).ToString();
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.Write(Output().Aggregate(string.Format("Case #{0}: ", i), (a, b) => a + b + Environment.NewLine));
    }
}