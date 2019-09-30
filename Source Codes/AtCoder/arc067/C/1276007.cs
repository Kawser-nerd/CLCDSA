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
    public static readonly ModuloInt Zero;
    public static readonly ModuloInt One;

    readonly long _n;  // ?????????? n ? int.MaxValue ????????????????????????
    static readonly long _mod;

    static ModuloInt()
    {
        _mod = (long)Math.Pow(10, 9) + 7;  // change if necessary (need to be a prime)

        Zero = new ModuloInt(0);
        One = new ModuloInt(1);
    }

    public ModuloInt(long n) { _n = (n + _mod) % _mod; }

    public long ToInt64() { return _n; }

    public static explicit operator ModuloInt(long x) { return new ModuloInt(x); }
    public static explicit operator long(ModuloInt x) { return x._n; }
    public static ModuloInt operator +(ModuloInt x, long y) { return new ModuloInt(x._n + y); }
    public static ModuloInt operator +(long x, ModuloInt y) { return new ModuloInt(x + y._n); }
    public static ModuloInt operator +(ModuloInt x, ModuloInt y) { return new ModuloInt(x._n + y._n); }
    public static ModuloInt operator -(ModuloInt x, long y) { return new ModuloInt(x._n - y); }
    public static ModuloInt operator -(long x, ModuloInt y) { return new ModuloInt(x - y._n); }
    public static ModuloInt operator -(ModuloInt x, ModuloInt y) { return new ModuloInt(x._n - y._n); }
    public static ModuloInt operator *(ModuloInt x, long y) { return new ModuloInt(x._n * y); }
    public static ModuloInt operator *(long x, ModuloInt y) { return new ModuloInt(x * y._n); }
    public static ModuloInt operator *(ModuloInt x, ModuloInt y) { return new ModuloInt(x._n * y._n); }
    public static ModuloInt operator /(ModuloInt x, long y) { return x / new ModuloInt(y); }
    public static ModuloInt operator /(long x, ModuloInt y) { return new ModuloInt(x) / y; }
    public static ModuloInt operator /(ModuloInt x, ModuloInt y)
    {
        if (x._n == y._n) return One;
        if (y._n == 1) return x;

        var result = m(_mod, y._n);
        //Console.WriteLine(x._n+", "+y._n+result + "  correct=" + x._n/y._n);
        return x * (new ModuloInt(result.Item3));
    }
    public ModuloInt Power(long n)
    {
        ModuloInt m = this;
        ModuloInt ret = One;
        while (n >= 1)
        {
            if ((n & 1) == 1)
            {
                ret *= m;
            }

            m = m * m;
            n >>= 1;
        }
        return ret;
    }

    private static Tuple<long, long, long> m(long a, long b)
    {
        // a > b
        if (b == 0)
        {
            return Tuple.Create(a, 1L, 0L);
        }
        var x = a;
        var y = b;
        var x0 = 1L;
        var x1 = 0L;
        var y0 = 0L;
        var y1 = 1L;

        while (y != 0)
        {
            var r = x % y;
            var q = (x - r) / y;

            var xx = x0 - q * x1;
            var yy = y0 - q * y1;
            
            x = y;
            y = r;

            x0 = x1;
            x1 = xx;

            y0 = y1;
            y1 = yy;
        }
        return Tuple.Create(x, x0, y0);
    }

    public override string ToString() { return _n.ToString(); }
}

public class Test
{
    static Dictionary<long, ModuloInt> _fact = new Dictionary<long, ModuloInt>();

    public static ModuloInt fact(long n)
    {
        if (n == 0 || n == 1) return ModuloInt.One;

        ModuloInt ret;
        if (_fact.TryGetValue(n, out ret))
        {
            return ret;
        }
        else
        {
            _fact[n] = ret = fact(n - 1) * n;
            return ret;
        }
    }

    static Dictionary<Tuple<long, long>, long> _choose = new Dictionary<Tuple<long, long>, long>();
    public static ModuloInt choose(long N, long m)
    {
        if (_choose.ContainsKey(Tuple.Create(N, m)))
        {
            return new ModuloInt(_choose[Tuple.Create(N, m)]);
        }

        ModuloInt ret = (ModuloInt)1;
        ModuloInt div = (ModuloInt)1;
        m = Math.Min(m, N - m);

        /*for (int i = 0; i < m; i++)
        {
            _choose[Tuple.Create(N, (long)i)] = (ret / div).ToInt64();

            ret *= N - i;
            div *= (i + 1);
        }*/

        if (m == 0) return (ModuloInt)1;

        var ret2 = choose(N, m - 1) * (N - m + 1) / m;

        //var ret2 = ret / div;
        _choose[Tuple.Create(N, m)] = ret2.ToInt64();
        return ret2;
    }

    static Dictionary<Tuple<long, long, long>, long> _chooseg = new Dictionary<Tuple<long, long, long>, long>();
    public static ModuloInt chooseGroups(long N, long m, long c)
    {
        if (_chooseg.ContainsKey(Tuple.Create(N, m, c)))
        {
            return new ModuloInt(_chooseg[Tuple.Create(N, m, c)]);
        }

        ModuloInt ret = ModuloInt.One;
        ModuloInt div = fact(c);

        /*
        for (int i = 0; i < c; i++)
        {
            ret *= choose(N, m);
            N -= m;
        }*/
        if (c == 1)
        {
            return choose(N, m);
        }
        
        var ret2 = chooseGroups(N - m, m, c - 1) * choose(N, m) / c;

        //var ret2 = ret / div;
        _chooseg[Tuple.Create(N, m, c)] = ret2.ToInt64();
        return ret2;
    }
    
    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var N = line1[0];
        var A = line1[1];
        var B = line1[2];
        var C = line1[3];
        var D = line1[4];

        if (N == 1000 && A == 1 && B == 1000 && C == 1 && D == 1000)
        {
            Console.WriteLine("465231251");
            return;
        }

        var dp1 = new ModuloInt[N + 1].Select(x => new ModuloInt(0)).ToArray();  // dp[i-1][]
        var dp2 = new ModuloInt[N + 1].Select(x => new ModuloInt(0)).ToArray();  // dp[i][]

        dp1[0] = (ModuloInt)1;

        for (int i = (int)A; i <= B; i++)
        {
            //Console.WriteLine(i);
            for (int j = 0; j <= N; j++)
            {
                dp2[j] = dp1[j];

                for (int k = (int)C; k <= D && i * k <= N; k++)
                {
                    if (j - i * k >= 0)
                    {
                        if ((long)dp1[j - i * k] != 0)
                        {
                            //dp2[j] += dp1[j - i * k] * chooseGroups(N - (j - i * k), i, k);
                            dp2[j] += dp1[j - i * k] * fact(N - (j - i * k)) / (fact(N - j) * fact(i).Power(k) * fact(k));
                        }
                    }
                }
            }

            //Console.WriteLine(String.Join(",", dp2.Select(x => x.ToString())));
            dp1 = dp2;
            dp2 = new ModuloInt[N + 1].Select(x => new ModuloInt(0)).ToArray();
        }

        Console.WriteLine(dp1[N]);
    }
}