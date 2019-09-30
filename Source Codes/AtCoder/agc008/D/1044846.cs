using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly string Yes = "Yes", No = "No";

    public void Solve()
    {
        int N = Reader.Int();
        var who = new int[N];
        var index = new int[N];
        for (int i = 0; i < N; i++)
        {
            who[i] = i + 1;
            index[i] = Reader.Int() - 1;
        }
        Console.WriteLine(Solve(N, who, index));
    }

    string Solve(int N, int[] who, int[] index)
    {
        Array.Sort(index, who);
        var ans = new int[N * N];
        int L = 0;
        var bit = new BinaryIndexedTree(N * N);
        for (int i = 0; i < N * N; i++)
            bit.Add(i, 1);

        for (int i = 0; i < N; i++)
        {
            if (bit.Sum(index[i]) < who[i]) return No;
            ans[index[i]] = who[i];
            bit.Add(index[i], -1);

            int num = who[i] - 1;
            for (; L < ans.Length && num > 0; L++)
                if (ans[L] == 0)
                {
                    num--;
                    bit.Add(L, -1);
                    ans[L] = who[i];
                }
            if (num > 0) return No;
        }
        for (int i = 0; i < N; i++)
            for (int num = N - who[i]; L < ans.Length && num > 0; L++)
                if (ans[L] == 0)
                {
                    if (L < index[i]) return No;
                    ans[L] = who[i];
                    num--;
                }

        return Yes + "\n" + string.Join(" ", ans);
    }
}

class BinaryIndexedTree
{
    private readonly int N;
    private readonly long[] A;

    public BinaryIndexedTree(int N)
    {
        this.N = N + 1;
        A = new long[N + 2];
    }
    public void Add(int i, long val)
    {
        if (i < 0) return;
        for (++i; i <= N; i += i & -i) A[i] += val;
    }
    public void Update(int i, long val)
    {
        Add(i, val - (Sum(i) - Sum(i - 1)));
    }
    public long Sum(int i) // [0, i]
    {
        if (i < 0) return 0;
        i = Math.Min(i + 1, N);
        long sum = 0;
        for (; i > 0; i &= i - 1) sum += A[i];
        return sum;
    }
    public long Sum(int L, int R) // [L, R)
    {
        return Sum(R - 1) - Sum(L - 1);
    }
    public int UpperBound(long val, int L = 0, int R = int.MaxValue)
    {
        for (L--, R = Math.Min(R, N); R - L > 1; )
        {
            int mid = L + R >> 1;
            if (Sum(mid) > val) R = mid;
            else L = mid;
        }
        return R;
    }
}


class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Range(N, Int); }
    public static int[][] IntTable(int H) { return Range(H, IntLine); }
    public static string[] StringArray(int N) { return Range(N, Next); }
    public static string[][] StringTable(int N) { return Range(N, () => Split(Line())); }
    public static string Line() { return reader.ReadLine().Trim(); }
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string[] Split(string s) { return s.Split(separator, op); }
    static string Next() { CheckNext(); return A[i++]; }
    static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}