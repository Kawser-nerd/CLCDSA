using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var s = Console.ReadLine();
        var counts = Enumerable.Range('a', 'z' - 'a' + 1).ToDictionary(c => (char)c, _ => 0L);
        foreach (var c in s)
        {
            counts[c]++;
        }

        var sum = counts.Sum(kv => kv.Value);
        var others = sum;
        var pattern = 1L;
        foreach (var kv in counts.Where(kv => kv.Value > 0))
        {
            pattern += kv.Value * (others - kv.Value);
            others -= kv.Value;
        }
        Console.WriteLine(pattern);
    }
}