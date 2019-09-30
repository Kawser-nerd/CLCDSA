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
    static readonly int[][] Index = { new[] { 1 ,0, 1, 0 }, new[] { 2, 1, 0, 3 },
                                      new[] { 3, 2, 3, 2 }, new[] { 0, 3, 2, 1 } };

    public void Solve()
    {
        int N = Reader.Int();
        var C = Reader.IntTable(N);
        var K = C.Select(c => Key(c)).ToArray();
        var M = new Dictionary<long, int>();
        for (int i = 0; i < N; i++) M[K[i]] = Mult(C[i]);
        var dic = new Dictionary<long, int>();
        ulong ans = 0;

        foreach (long k in K)
            dic[k] = dic.ContainsKey(k) ? dic[k] + 1 : 1;
        for (int a = 0; a < N - 1 && dic[K[a]]-- > 0; a++)
            for (int b = a + 1; b < N && dic[K[b]]-- > 0; dic[K[b]]++, b++)
                for (int r = 0; r < 4; r++, Rotate(C[b]))
                    ans += (ulong)Count(C[a], C[b], dic, M);

        Console.WriteLine(ans);
    }

    private long Count(int[] A, int[] B, Dictionary<long, int> dic, Dictionary<long, int> Mult)
    {
        var pattern = new Dictionary<long, int>();
        foreach (var i in Index)
        {
            long k = Key(new[] { A[i[0]], A[i[1]], B[i[2]], B[i[3]] });
            if (!dic.ContainsKey(k)) return 0;
            pattern[k] = pattern.ContainsKey(k) ? pattern[k] + 1 : 1;
        }
        long num = 1;
        foreach (long k in pattern.Keys)
            for (int i = 0; i < pattern[k]; i++)
                num *= (dic[k] - i) * Mult[k];
        return num;
    }

    void Rotate(int[] a) { int t = a[3]; Array.Copy(a, 0, a, 1, 3); a[0] = t; }

    long Key(int[] a)
    {
        long min = long.MaxValue;
        for (int r = 0; r < 4; r++, Rotate(a))
            min = Math.Min(min, a[0] * (long)1e9 + a[1] * (long)1e6 + a[2] * 1000 + a[3]);
        return min;
    }

    int Mult(int[] a)
    {
        if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) return 4;
        if (a[0] == a[2] && a[1] == a[3]) return 2;
        return 1;
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