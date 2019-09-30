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
        int[] NM = IntLine();
        int N = NM[0], M = NM[1];
        int[,] Edge = new int[N, N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Edge[i, j] = (i == j ? 0 : INF);
        List<int[]> LastEdge = new List<int[]>();

        for (int i = 0; i < M; i++)
        {
            int[] box = IntLine();
            if (box[0] == 1) { LastEdge.Add(box); }
            else
            {
                Edge[box[0] - 1, box[1] - 1] = box[2];
                Edge[box[1] - 1, box[0] - 1] = box[2];
            }
        }
        //WF
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    Edge[j, k] = Math.Min(Edge[j, k], Edge[j, i] + Edge[i, k]);

        long ans = INF;
        long temp = 0;
        for (int i = 0; i < LastEdge.Count(); i++)
        {
            for (int j = i + 1; j < LastEdge.Count(); j++)
            {
                temp = Edge[LastEdge[i][1] - 1, LastEdge[j][1] - 1] + LastEdge[i][2] + LastEdge[j][2];
                ans = Math.Min(temp, ans);
            }
        }
        if (ans == INF) ans = -1;
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