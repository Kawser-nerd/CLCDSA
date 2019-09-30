using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).ToArray();
        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] != (n - 1) - ((i / 2) * 2))
            {
                Console.WriteLine(0);
                return;
            }
        }

        Console.WriteLine(power(2, n / 2));
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