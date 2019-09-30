using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    int Solve(List<long> A)
    {
        List<long> a = new List<long>(A);
        int count = 0;
        while (a.Count > 0)
        {
            long min = a.Min();
            int idx = a.FindIndex(aa => aa == min);
            count += Math.Min(idx, a.Count - idx - 1);
            a.RemoveAt(idx);
        }
        return count;
    }

    static void swap(List<long> a, int i, int j)
    {
        long temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static IEnumerable<string> Output()
    {
        Console.ReadLine();
        yield return new B().Solve(Console.ReadLine().Split(' ').Select(i=>long.Parse(i)).ToList()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}