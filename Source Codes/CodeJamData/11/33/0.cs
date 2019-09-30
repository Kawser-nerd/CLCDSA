using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

static class ProgramA
{
    static long h, l;
    static long cgcd(long a, long b)
    {
        long r;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    static long clcd(long a, long b)
    {
        long r = cgcd(a, b);
        long x = a / r;
        if ((double)x * b > h)
            return -1;
        return x * b;
    }
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('c', ProblemType.Large, 0))
        {
            int tcase = prob.ReadLineInt32();
            for (int cases = 0; cases < tcase; cases++)
            {
                long[] a = prob.ReadInt64Array();
                int n = (int)a[0];
                l = a[1];
                h = a[2];
                List<long> x = new List<long>();
                long[] ff = prob.ReadInt64Array();
                for (int i = 0; i < n; i++)
                    x.Add(ff[i]);
                long[] f = x.Distinct().ToArray();
                Array.Sort(f);
                n = f.Length;
                long[] gcd = new long[n];
                long[] lcd = new long[n];
                int start = 0;
                while (f[start] == 0 && start < n)
                    start++;
                lcd[start] = f[start];
                for (int i = start+1; i < n; i++)
                {
                    if (lcd[i - 1] == -1)
                        lcd[i] = -1;
                    else
                        lcd[i] = clcd(lcd[i - 1], f[i]);
                }
                gcd[n - 1] = f[n - 1];
                for (int i = n - 2; i >= start; i--)
                    gcd[i] = cgcd(f[i], gcd[i + 1]);
                long ans = getMin(l, h, gcd[0]);
                for (int i = start; i < n-1; i++)
                {
                    if (i < n-2 && f[i] == f[i+1])
                        continue;
                    if (lcd[i] == -1)
                        break;
                    if (gcd[i+1] % lcd[i] != 0)
                        continue;
                    if (lcd[i] <= gcd[i+1])
                    {
                        long tl = (l + lcd[i] - 1) / lcd[i];
                        long th = h / lcd[i];
                        long tans = getMin(tl, th, gcd[i+1] / lcd[i]) * lcd[i];
                        if (tans >= 0 && (ans == -1 || ans > tans))
                            ans = tans;
                    }
                }
                if (lcd[n - 1] != -1)
                {
                    long ttans = (l + lcd[n - 1] - 1) / lcd[n - 1] * lcd[n - 1];
                    if (ttans <= h && (ans == -1 || ttans < ans))
                        ans = ttans;
                }
                if (ans == -1)
                    prob.OutputCase("NO");
                else
                    prob.OutputCase(ans.ToString());
            }
        }
    }

    private static long getMin(long l, long h, long p)
    {
        if (l > h)
            return -1;
        if (h - l <= 1000)
        {
            for (long i = l; i <= h; i++)
                if (p % i == 0)
                    return i;
            return -1;
        }
        long ans = p;
        for (int i = 2; i <= (long)Math.Sqrt(p); i++)
        {
            if (p % i != 0)
                continue;
            if (l <= i && i <= h)
                return i;
            if (l <= p / i && p / i <= h)
                ans = p / i;
        }
        if (l <= ans && ans <= h)
            return ans;
        return -1;
    }
}
