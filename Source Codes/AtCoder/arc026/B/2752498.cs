using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        string ans;
        var n = long.Parse(Console.ReadLine().Trim());
        if (n == 1) { ans = "Deficient"; goto end; }
        var rn = (long)Math.Sqrt(n);
        var ret = new List<long> { 1 };
        for (long i = 2; i <= rn; i++)
            if (n % i == 0)
            {
                ret.Add(i);
                if (n / i != i) ret.Add(n / i);
            }
        var rets = ret.Sum();
        if (rets == n) ans = "Perfect";
        else if (rets > n) ans = "Abundant";
        else ans = "Deficient";
        end:;
        Console.WriteLine(ans);
    }
}