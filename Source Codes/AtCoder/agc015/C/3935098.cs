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
        int N = inp[0], M = inp[1], Q = inp[2];
        int[,] field = new int[N, M];
        for (int i = 0; i < N; i++)
        {
            int[] b = Console.ReadLine().ToCharArray().Select(c => int.Parse(c.ToString())).ToArray();
            for (int j = 0; j < M; j++) field[i, j] = b[j];
        }
        int[,] Qs = new int[Q, 4];
        for (int i = 0; i < Q; i++)
        {
            int[] b = IntLine().Select(v => v - 1).ToArray();
            for (int j = 0; j < 4; j++) Qs[i, j] = b[j];
        }

        CumulativeSum node = new CumulativeSum(N, M);
        Array.Copy(field, node.Info, field.Length);
        node.Run();
        CumulativeSum e = new CumulativeSum(N * 2 - 1, M * 2 - 1);
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < M; j++)
            {
                if (field[i, j] == 1 && field[i, j - 1] == 1)
                {
                    e.Info[i * 2, j * 2 - 1] = 1;
                }
            }
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (field[i, j] == 1 && field[i - 1, j] == 1)
                {
                    e.Info[i * 2 - 1, j * 2] = 1;
                }
            }
        }
        e.Run();

        for (int i = 0; i < Q; i++)
        {
            int y1 = Qs[i, 0], x1 = Qs[i, 1], y2 = Qs[i, 2], x2 = Qs[i, 3];
            int ns = node.Info[y2, x2];
            if (x1 != 0 && y1 != 0)
            {
                ns += -node.Info[y2, x1 - 1] - node.Info[y1 - 1, x2] + node.Info[y1 - 1, x1 - 1];
            }
            else if (y1 != 0)
            {
                ns += -node.Info[y1 - 1, x2];
            }
            else if (x1 != 0)
            {
                ns += -node.Info[y2, x1 - 1];
            }
            y1 *= 2;
            y2 *= 2;
            x1 *= 2;
            x2 *= 2;
            int es = e.Info[y2, x2];
            if (x1 != 0 && y1 != 0)
            {
                es += -e.Info[y2, x1 - 1] - e.Info[y1 - 1, x2] + e.Info[y1 - 1, x1 - 1];
            }
            else if (y1 != 0)
            {
                es += -e.Info[y1 - 1, x2];
            }
            else if (x1 != 0)
            {
                es += -e.Info[y2, x1 - 1];
            }
            Console.WriteLine(ns-es);
        }
    }
}

public class CumulativeSum
{
    public int[,] Info { get; set; }

    public CumulativeSum(int N, int M)
    {
        Info = new int[N, M];
    }

    public void Run()
    {
        RightAdd();
        DownAdd();
    }

    private void RightAdd()
    {
        for (int i = 0; i < Info.GetLength(0); i++)
        {
            for (int j = 1; j < Info.GetLength(1); j++)
            {
                Info[i, j] += Info[i, j - 1];
            }
        }
    }

    private void DownAdd()
    {
        for (int i = 1; i < Info.GetLength(0); i++)
        {
            for (int j = 0; j < Info.GetLength(1); j++)
            {
                Info[i, j] += Info[i - 1, j];
            }
        }
    }

    public void Draw()
    {
        for (int i = 0; i < Info.GetLength(0); i++)
        {
            for (int j = 0; j < Info.GetLength(1); j++)
            {
                Console.Write(Info[i, j] + " ");
            }
            Console.WriteLine();
        }
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