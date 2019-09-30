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
        int[,] e = new int[N, N];
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) e[i, j] = (i == j ? 0 : INF);
        List<int[]> LastList = new List<int[]>();
        for (int i = 0; i < M; i++)
        {
            int[] b = IntLine();
            if (b[0] == 1) LastList.Add(b);
            else
            {
                e[b[0] - 1, b[1] - 1] = b[2];
                e[b[1] - 1, b[0] - 1] = b[2];
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    e[j, k] = Math.Min(e[j, k], e[j, i] + e[i, k]);

        long ans = INF;
        for (int i = 0; i < LastList.Count(); i++)
        {
            for (int j = i + 1; j < LastList.Count(); j++)
            {
                long a = e[LastList[i][1] - 1, LastList[j][1] - 1] + LastList[i][2] + LastList[j][2];
                ans = Math.Min(ans,a);
            }
        }
        Console.WriteLine(ans == INF ? -1:ans);

    }
}

public class Permutation
{
    private static List<int> line;
    public List<List<int>> PermList { get; set; }

    public Permutation(List<int> list) { line = new List<int>(list); }

    public void Calc(List<int> list)
    {
        if (list.Count == line.Count())
        {
            PermList.Add(list);
            return;
        }
        foreach (int i in line)
        {
            if (!list.Contains(i))
            {
                List<int> nextlist = new List<int>(list);
                nextlist.Add(i);
                Calc(nextlist);
            }
        }
    }

    public void Draw()
    {
        foreach (var l in PermList)
        {
            l.ForEach(v => Console.Write(v + " "));
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