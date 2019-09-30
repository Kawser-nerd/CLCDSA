using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    int Solve(int R, int C, int N)
    {
        var cell = new bool[R * C];
        return Enumerable.Range(0, 1 << (R * C)).Min(i =>
        {
            int count = 0;
            for (int j = 0; j < R * C; j++)
            {
                cell[j] = ((i >> j) & 1) == 0;
                if (cell[j]) count++;
            }
            if (count != N) return int.MaxValue;
            var val = 0;
            for (int x = 0; x < C; x++)
            {
                for (int y = 0; y < R; y++)
                {
                    if (cell[x * R + y])
                    {
                        if (x < C - 1 && cell[(x + 1) * R + y]) val++;
                        if (y < R - 1 && cell[x * R + y + 1]) val++;
                    }
                }
            }
            return val;
        });
    }

    static IEnumerable<string> Output()
    {
        var RCN =  Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new B().Solve(RCN[0], RCN[1], RCN[2]).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}