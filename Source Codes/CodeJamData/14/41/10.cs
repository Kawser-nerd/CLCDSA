using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    int Solve(int X, List<int> S)
    {
        int count = 0;
        S.Sort();
        int j = 0;
        for (int i = S.Count - 1; i >= j; i--)
        {
            count++;
            if (i == j) continue;
            if (S[i] + S[j] <= X) j++;
        }
        return count;
    }

    static IEnumerable<string> Output()
    {
        var x = int.Parse(Console.ReadLine().Split(' ')[1]);
        yield return new A().Solve(x,Console.ReadLine().Split(' ').Select(int.Parse).ToList()).ToString(); ;
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}