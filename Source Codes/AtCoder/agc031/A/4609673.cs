using System.Collections.Generic;
using System;

public class Hello
{
    const  int MOD = 1000000007;
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var s = Console.ReadLine().Trim();
        var d = new Dictionary<char, int>();
        for (int i = 0; i < n; i++)
            if (d.ContainsKey(s[i])) d[s[i]]++;
            else d[s[i]] = 1;
        var ans = 1L;
        foreach(var x in d)
        {
            ans *= (x.Value + 1);
            ans %= MOD;
        }
        Console.WriteLine(ans - 1);
    }
}