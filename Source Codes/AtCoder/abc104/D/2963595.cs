using System;

public class Hello
{
    public static int MOD = 1000000007;
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var sL = s.Length;
        var a1 = new int[sL];
        var q1 = new int[sL];
        var c2 = new int[sL];
        var q2 = new int[sL];
        var ca1 = 0; var cc2 = 0; var cq1 = 0; var cq2 = 0;
        for (int i = 0; i < s.Length; i++)
        {
            a1[i] = ca1; q1[i] = cq1;
            c2[sL - 1 - i] = cc2; q2[sL - 1 - i] = cq2;
            if (s[i] == 'A') ca1++;
            else if (s[i] == '?') cq1++;
            if (s[sL - 1 - i] == 'C') cc2++;
            else if (s[sL - 1 - i] == '?') cq2++;
        }
        var ans = 0L;
        for (int i = 1; i <= sL - 2; i++)
        {
            if (s[i] == 'B' | s[i] == '?')
            {
                var acount = (long)a1[i];
                var qcount = q1[i];
                var wwa = (acount * (get3power(3, qcount))) % MOD;
                if (qcount >= 1) wwa += (qcount * (get3power(3, qcount - 1))) % MOD;
                wwa %= MOD;
                var ccount = c2[i];
                var qcount2 = q2[i];
                var wwc = (ccount * (get3power(3, qcount2))) % MOD;
                if (qcount2 >= 1) wwc += (qcount2 * (get3power(3, qcount2 - 1))) % MOD;
                wwc %= MOD;
                ans += (wwa * wwc) % MOD;
                ans %= MOD;
            }
        }
        Console.WriteLine(ans);
    }
    public static long get3power(int a, int b)
    {
        if (b == 0) return 1L;
        if (b == 1) return (long)(a % MOD);
        var k = (int)(Math.Log10(b) / Math.Log10(2)) + 1;
        var p = new long[k];
        p[0] = (long)a;
        for (int i = 1; i < k; i++)
            p[i] = (p[i - 1] * p[i - 1]) % MOD;
        var ret = 1L;
        for (int i = 0; i < k; i++)
            if (((b >> i) & 1) == 1)
            {
                ret *= p[i];
                ret %= MOD;
            }
        return ret;
    }
}