using System;
using System.Linq;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var cat = Console.ReadLine().Split().Select(int.Parse).ToArray();

        var max = cat.Max();
        var maxCount = cat.Count(c => c == max);
        var min = cat.Min();
        var minCount = cat.Count(c => c == min);

        bool ok = false;
        if (max == min)
        {
            // 3 3 3 3 3 3      5 5 5 5 5 5
            // a b c a b c      a b c d e f
            if (2 * max <= n || max == n - 1)
            {
                ok = true;
            }
        }
        else if (max == min + 1)
        {
            // 3 3 4 4 4 4
            // a b c d c d
            if (minCount <= min && 2 * (max - minCount) <= maxCount)
            {
                ok = true;
            }
        }

        Console.WriteLine(ok ? "Yes" : "No");
    }
}