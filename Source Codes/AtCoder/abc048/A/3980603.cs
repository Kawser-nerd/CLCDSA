using System;
using System.Collections.Generic;
using System.Linq;
using static AtCoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        Console.WriteLine("A" + Console.ReadLine().Split(' ')[1][0] + "C");
    }
}

public class AtCoder
{
    public static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static int GCD(int a, int b)
    {
        if (a < b) Swap(ref a, ref b);
        int d = a % b;
        while (b != 0)
        {
            d = a % b;
            a = b;
            b = d;
        }
        return a;
    }
    public static long LCM(int a, int b)
    {
        return (long)a * b / GCD(a, b);
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
    public static long RepPow(long x, long p, long m = 1000000007)
    {
        if (p == 1) return x % m;
        long b = RepPow(x, p / 2, m) % m;
        if (p % 2 == 0) { return (b * b) % m; }
        else { return (x * ((b * b) % m)) % m; }
    }
    public static long LongRead()
    {
        return long.Parse(Console.ReadLine());
    }
    public static long[] LongLine()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
    public static int[] IntLine()
    {
        return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }
}