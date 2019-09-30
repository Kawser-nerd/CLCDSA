//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class ModuloInt
{
    readonly long _n;
    readonly long _mod;

    public ModuloInt(long n, long mod)
    {
        _n = n % mod;
        _mod = mod;
    }

    public long ToInt64()
    {
        return _n;
    }

    public static ModuloInt operator +(ModuloInt x, long y) { return new ModuloInt(x._n + y, x._mod); }
    public static ModuloInt operator +(long x, ModuloInt y) { return new ModuloInt(x + y._n, y._mod); }
    public static ModuloInt operator +(ModuloInt x, ModuloInt y)
    {
        if (x._mod != y._mod) { throw new Exception(); }
        return new ModuloInt(x._n + y._n, x._mod);
    }
    public static ModuloInt operator -(ModuloInt x, long y) { return new ModuloInt(x._n - y, x._mod); }
    public static ModuloInt operator -(long x, ModuloInt y) { return new ModuloInt(x - y._n, y._mod); }
    public static ModuloInt operator -(ModuloInt x, ModuloInt y)
    {
        if (x._mod != y._mod) { throw new Exception(); }
        return new ModuloInt(x._n - y._n, x._mod);
    }
    public static ModuloInt operator *(ModuloInt x, long y) { return new ModuloInt(x._n * y, x._mod); }
    public static ModuloInt operator *(long x, ModuloInt y) { return new ModuloInt(x * y._n, y._mod); }
    public static ModuloInt operator *(ModuloInt x, ModuloInt y)
    {
        if (x._mod != y._mod) { throw new Exception(); }
        return new ModuloInt(x._n * y._n, x._mod);
    }
}

public class Test
{
    public static void Main()
    {
        var N = long.Parse(Console.ReadLine());

        var factors = new int[N + 1];  // factors[i] ? i ????? (??? i >= 2)

        for (int i = 2; i <= N; i++)
        {
            // i ????????
            int num = i;
            for (int j = 2; num != 1; j++)
            {
                while (num % j == 0)
                {
                    factors[j]++;
                    num /= j;
                }
            }
        }

        //Console.WriteLine(string.Join(",", factors));

        var result = new ModuloInt(1, (long)Math.Pow(10, 9) + 7);

        foreach (var factor in factors)
        {
            result *= (factor + 1);  // ????0????1???????factor????????????factor+1???
        }

        Console.WriteLine(result.ToInt64());
    }
}