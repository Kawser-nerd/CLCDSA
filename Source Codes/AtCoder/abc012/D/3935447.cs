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
        int[] inp = IntLine();
        int N = inp[0], M = inp[1];
        int[,] e = new int[N, N];
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) e[i, j] = INF;
        for (int i = 0; i < M; i++)
        {
            inp = IntLine();
            e[inp[0] - 1, inp[1] - 1] = e[inp[1] - 1, inp[0] - 1] = inp[2];
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    e[j, k] = Math.Min(e[j, k], e[j, i] + e[i, k]);
        long ans = INF;
        for (int i = 0; i < N; i++)
        {
            long n_ans = 0;
            for (int j = 0; j < N; j++)
            {
                if (i == j) continue;
                n_ans = Math.Max(e[i, j], n_ans);
            }
            ans = Math.Min(ans, n_ans);
        }
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