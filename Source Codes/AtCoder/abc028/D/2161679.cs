using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        long[] nk = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long all = nk[0] * nk[0] * nk[0];
        Console.WriteLine((double)((nk[1] - 1) * (nk[0] - nk[1]) * 6 + (nk[0] - 1) * 3 + 1) / all);
    }

    static int power(int n, int m)
    {
        const int mod = 1000000007;
        long pow = n;
        long res = 1;
        while (m > 0)
        {
            if ((m & 1) == 1) res = (res * pow) % mod;
            pow = (pow * pow) % mod;
            m >>= 1;
        }
        return (int)res;
    }
}