using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
class P
{
    static int mod = 1000000007;
    static void Main()
    {
        string s = Console.ReadLine();
        int n = s.Length;
        int[,] count = new int[n + 1, 4];
        for (int i = 1; i <= n; i++)
        {
            count[i, 0] = count[i - 1, 0];
            count[i, 1] = count[i - 1, 1];
            count[i, 2] = count[i - 1, 2];
            count[i, 3] = count[i - 1, 3];
            if (s[i - 1] == 'A')
                count[i, 0]++;
            if (s[i - 1] == 'B')
                count[i, 1]++;
            if (s[i - 1] == 'C')
                count[i, 2]++;
            if (s[i - 1] == '?')
                count[i, 3]++;
        }
        long ans = 0;
        if (count[n, 3] >= 3)
        {//'?'?3???
            long q = count[n, 3];
            long p = Math.Max(q - 3, 0);
            long t = (q * (q - 1)) % mod;
            t = (t * (q - 2)) % mod;
            t = (t * POW(6, mod - 2)) % mod;
            ans = (ans + (t * POW(3, p)) % mod) % mod;
        }
        if (count[n, 3] >= 2)
        {//'?'?2???
            for (int i = 0; i < n; i++)
            {
                long p = Math.Max(count[n, 3] - 2, 0);
                if (s[i] == 'A')
                {
                    long q = count[n, 3] - count[i + 1, 3];
                    ans = (ans + ((q * (q - 1)) / 2 % mod * POW(3, p)) % mod) % mod;
                }
                if (s[i] == 'B')
                {
                    long ql = count[i, 3];
                    long qr = count[n, 3] - count[i + 1, 3];
                    ans = (ans + (ql * qr) % mod * POW(3, p) % mod) % mod;
                }
                if (s[i] == 'C')
                {
                    long q = count[i, 3];
                    ans = (ans + (q * (q - 1)) / 2 % mod * POW(3, p) % mod) % mod;
                }
            }
        }
        long q0 = 0;
        {//'?'?0???
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++)
                if (s[i] != '?')
                    sb.Append(s[i]);
            q0 = Calc(sb.ToString());
            ans += q0 * POW(3, count[n, 3]) % mod;
            ans %= mod;
        }
        long q1 = 0;
        if (count[n, 3] >= 1)
        {//'?'?1???
            long q = count[n, 3];
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++)
            {
                if (s[i] != '?')
                    sb.Append(s[i]);
                else
                    sb.Append('A');
            }
            ans = (ans + (Calc(sb.ToString()) - q0) * POW(3, q - 1) % mod) % mod;
            sb = new StringBuilder();
            for (int i = 0; i < n; i++)
            {
                if (s[i] != '?')
                    sb.Append(s[i]);
                else
                    sb.Append('B');
            }
            ans = (ans + (Calc(sb.ToString()) - q0) * POW(3, q - 1) % mod) % mod;
            sb = new StringBuilder();
            for (int i = 0; i < n; i++)
            {
                if (s[i] != '?')
                    sb.Append(s[i]);
                else
                    sb.Append('C');
            }
            ans = (ans + (Calc(sb.ToString()) - q0) * POW(3, q - 1) % mod) % mod;
        }
        while (ans < 0)
            ans += mod;
        Console.WriteLine(ans);
    }
    static long POW(long a, long n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return a % mod;
        long m = n / 2;
        if (n % 2 == 0)
        {
            long temp = POW(a, m);
            return (temp * temp) % mod;
        }
        else
        {
            long temp = POW(a, m);
            return ((temp * temp) % mod * a) % mod;
        }
    }
    static long Calc(string s) //'A''B''C'????????ABC????
    {
        try {
            long[] a = new long[s.Length + 1];
            long[] b = new long[s.Length + 1];
            long[] c = new long[s.Length + 1];
            for (int i = 1; i <= s.Length; i++)
            {
                a[i] = a[i - 1];
                b[i] = b[i - 1];
                c[i] = c[i - 1];
                if (s[i - 1] == 'A')
                    a[i]++;
                if (s[i - 1] == 'B')
                    b[i]++;
                if (s[i - 1] == 'C')
                    c[i]++;
            }
            long[] bc = new long[s.Length];
            for (int i = 0; i < s.Length; i++)
                if (s[i] == 'B')
                    bc[i] = c[s.Length] - c[i + 1];
            long[] bcs = new long[s.Length];
            bcs[s.Length - 1] = bc[s.Length - 1];
            for (int i = s.Length - 2; i >= 0; i--)
                bcs[i] = bcs[i + 1] + bc[i];
            long ans = 0;
            for (int i = 0; i < s.Length - 1; i++)
                if (s[i] == 'A')
                    ans = (ans + bcs[i + 1] % mod) % mod;
            return ans;
        }
        catch { return 0; }
    }
}