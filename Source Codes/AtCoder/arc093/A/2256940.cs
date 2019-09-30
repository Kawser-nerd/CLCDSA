using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        a.Insert(0, 0);
        a.Add(0);

        var sum = Enumerable.Range(0, n + 1).Select(i => Math.Abs(a[i + 1] - a[i])).Sum();

        var answer = new StringBuilder();
        for (int i = 1; i <= n; i++)
        {
            var x = sum - (Math.Abs(a[i] - a[i - 1]) + Math.Abs(a[i + 1] - a[i])) + Math.Abs(a[i + 1] - a[i - 1]);
            answer.Append(x);
            answer.Append("\n");
        }

        Console.WriteLine(answer);
    }
}