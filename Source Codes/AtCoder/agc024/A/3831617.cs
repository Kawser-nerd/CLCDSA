using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    public static void Main()
    {
        long[] ABCK = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        long A = ABCK[0], B = ABCK[1], C = ABCK[2], K = ABCK[3];
        long ans = ( K%2==0 ? A - B : B - A );
        Console.WriteLine(ans);
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
    public static int[] SpIntRead(char c)
    {
        return Console.ReadLine().Split(c).Select(int.Parse).ToArray();
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
}