using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    private const int INF = 1000000000;
    public static void Main()
    {
        int N = IntRead();
        var box = SpRead(' ').Select(long.Parse).ToArray();
        long[] dp = Enumerable.Repeat<long>(INF, N).ToArray();
        dp[0] = 0;
        for (int i = 0; i < N - 1; i++)
        {
            dp[i + 1] = Math.Min(dp[i + 1], dp[i] + Math.Abs(box[i + 1] - box[i]));
            if (i + 1 != N - 1)
            {
                dp[i + 2] = Math.Min(dp[i + 2], dp[i] + Math.Abs(box[i + 2] - box[i]));
            }
        }
        //dp.ToList().ForEach(i => Console.WriteLine(i));
        Console.WriteLine(dp[N-1]);
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
}