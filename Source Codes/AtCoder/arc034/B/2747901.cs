using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var ret = new List<long>();
        var n = long.Parse(Console.ReadLine().Trim());
        var k = n.ToString().Length;
        for (long i = Math.Max(0, n - 9 * k); i <= n - 1; i++)
            if (i + getSum(i) == n) ret.Add(i);
        Console.WriteLine(ret.Count());
        if (ret.Count() > 0)
            foreach (var x in ret) Console.WriteLine(x);
    }
    public static int getSum(long n)
    {
        var s = n.ToString();
        var ret = 0;
        for (int i = 0; i < s.Length; i++)
            ret += int.Parse(s[i].ToString());
        return ret;
    }
}