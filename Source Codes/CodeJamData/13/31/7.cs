using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    public long Solve(string str, int n)
    {
        long ret = 0;
        int prev = 0;
        for (int i = 0; i < str.Length; i++)
        {
            var c = 0;
            var i0 = i;
            for (; i<str.Length && !"aiueo".Contains(str[i]); i++) c++;
            if (c >= n)
            {
                ret += 1L * (i0-prev) * (str.Length - i0 - n + 1);
                for (int j = i0; j <= i0 + c - n; j++)
                {
                    ret += str.Length - j - n + 1;
                }
                prev = i0 + c - n + 1;
            }
        }
        return ret;
    }

    static IEnumerable<string> Output() {
        var line = Console.ReadLine().Split(' ');
        yield return new A().Solve(line[0],int.Parse(line[1])).ToString(); 
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}

