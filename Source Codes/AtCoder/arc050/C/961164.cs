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
    public void Solve()
    {
        long A = Reader.Long(), B = Reader.Long(), M = Reader.Long();
        long g = GCD(A, B);
        long ans = Ones(A, M) * F(B, g, M) % M;
        Console.WriteLine(ans);
    }

    long Ones(long N, long mod)
    {
        long res = 0;
        long ones = 1;
        for (long bit = 1; bit <= N; bit <<= 1)
        {
            if ((N & bit) == bit)
                res = (ones * ModPower(10, N & bit - 1, mod) + res) % mod;
            ones = ones * (ModPower(10, bit, mod) + 1) % mod;
        }
        return res;
    }

    long F(long N, long g, long M)
    {
        // N: 12, g: 3
        // 111111111111 / 111 => 1001001001

        N = N / g - 1;
        long res = 0;
        long x = ModPower(10, g - 1, M);

        for (long bit = 1; bit <= N; bit <<= 1)
        {
            if ((N & bit) == bit)
                res = (x * ModPower(10, g * (N & bit - 1), M) + res) % M;
            x = x * (1 + ModPower(10, g * bit, M)) % M;
        }
        return (res * 10 + 1) % M;
    }

    long GCD(long a, long b)
    {
        while (b != 0) { long r = a % b; a = b; b = r; }
        return a;
    }

    static long ModPower(long x, long n, long mod) // x ^ n
    {
        long res = 1;
        x = (x % mod + mod) % mod;
        while (n > 0)
        {
            if ((n & 1) == 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
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
    static string[] Split(string s) { return s.Split(separator, op); }
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
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