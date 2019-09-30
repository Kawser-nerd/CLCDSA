using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    private const long INF = 1000000007;
    public static void Main()
    {
        long A = LongRead();
        long B = LongRead();
        long C = LongRead();

        long BC = (B * C);
        long AB = (B * A);
        long AC = (A * C);

        long c1 = (BC - AB % INF) % INF;
        long c2 = (AC - BC % INF + AB) % INF;
        long c = (c1 * Pow(c2, INF - 2) % INF);

        long r1 = (BC - AC % INF) % INF;
        long r2 = (AB - BC % INF + AC) % INF;
        long r = (r1 * Pow(r2, INF - 2)) % INF;

        Console.WriteLine(r + " " + c);
    }

    public static long Pow(long x, long p)
    {
        long ans = 1;
        while (p > 0)
        {
            if (p % 2 == 1)
            {
                ans *= x;
                ans %= INF;
            }
            x *= x;
            x %= INF;
            //p >>= 1;
            p /= 2;
        }
        return ans;
    }
}

public class Atcoder
{
    public static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static long LCM(long a, long b)
    {
        long c = a * b;
        if (a < b) Swap(ref a, ref b);
        long d = a % b;
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
    public static string ToConvertBit(int N, int e)
    {
        string ret = "";
        int r = 0;
        while (N != 0)
        {
            r = N % e;
            ret += r.ToString();
            N -= r;
            N /= e;
        }
        ret = StrReverce(ret);
        return ret;
    }
    public static int IntRead()
    {
        return int.Parse(Console.ReadLine());
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