using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        long N = LongRead();
        var Li = LongLine().OrderBy(v => v);
        long ans = 0;
        for (int i = 0; i < N; i++) ans += Li.ElementAt(2 * i);
        Console.WriteLine(ans);
    }
}

public class Factorization
{
    private static long N;

    public Factorization(long n) { N = n; }

    //????????
    public static long GCD(long a, long b)
    {
        if (a < b) return GCD(b, a);
        long r;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    //????
    public static bool IsPrime(long n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        double root = Math.Sqrt(n);
        for (int i = 3; i <= root; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }

    //????
    private static int[] TryPrimes = new int[] { 2, 3, 5, 7, 11 };
    public long TryAllocation(long p)
    {
        long count = 0;
        while (N % p == 0)
        {
            count++;
            N /= p;
        }
        return count;
    }

    private int[] xi = new int[] { 13, 17, 19, 23, 29 };
    private long f(long x, int suffix)
    {
        return (xi[suffix % xi.Count()] * x + suffix) % N;
    }

    //n???
    public long PollardsRho(long n, int suffix = 0)
    {
        //?????????????
        if (IsPrime(n)) return n; //????
        long x = 2, y = 2, d = 1;
        while (d == 1)
        {
            x = f(x, suffix);
            y = f(f(y, suffix), suffix);
            d = GCD(Math.Abs(x - y), n);
        }
        if (d == n)
        {
            //f(x)??????
            return PollardsRho(n, suffix + 1);
        }
        return d;
    }

    public IEnumerable<long> Calc()
    {
        //?????????
        foreach (var prime in TryPrimes)
        {
            var box = TryAllocation(prime);
            for (int i = 0; i < box; i++) yield return prime;
        }

        //???Rho???
        while (true)
        {
            if (N == 1) break;
            var ret = PollardsRho(N);
            yield return ret;
            N /= ret;
        }
    }
}


public class Atcoder
{
    static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static int LCM(int a, int b)
    {
        int c = a * b;
        if (a < b) Swap(ref a, ref b);
        int d = a % b;
        while (d != 0)
        {
            a = b;
            b = d;
            d = a % b;
        }
        return c / b;
    }
    public static string StrReverce(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static int IntRead()
    {
        return int.Parse(Console.ReadLine());
    }
    public static bool IsPrime(int n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        //double sqrtNum = Math.Sqrt(n);
        for (int i = 3; i < n; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
    public static string[] SpRead(char c)
    {
        return Console.ReadLine().Split(c);
    }
    public static long[] LSRead()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
    public static long Combination(int n, int r)
    {
        if (n == r) return 1;
        return
            Enumerable.Range((n - r + 1), r).ToList().Aggregate((now, next) => now * next) /
            Enumerable.Range(1, r).ToList().Aggregate((now, next) => now * next);
    }
    public static long Permutation(int n, int r)
    {
        if (n == r) return 1;
        return
            Enumerable.Range((n - r), r).ToList().Aggregate((now, next) => now * next);
    }
    public static long LongRead()
    {
        return long.Parse(Console.ReadLine());
    }
    public static long[] LongLine()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
}