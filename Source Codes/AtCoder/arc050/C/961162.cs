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

    long GCD(long a, long b)
    {
        while (b != 0) { long r = a % b; a = b; b = r; }
        return a;
    }

    long Ones(long N, long mod)
    {
        long res = 0;
        long ones = 1;
        long added = 0;
        for (long i = 1; N > 0; i *= 2, N /= 2)
        {
            if (N % 2 == 1)
            {
                res = (ones * (long)BigInteger.ModPow(10, added, mod) + res) % mod;
                added += i;
            }
            ones = ones * ((long)BigInteger.ModPow(10, i, mod) + 1) % mod;
        }
        return res;
    }

    long F(long N, long g, long M)
    {
        // N: 12, g: 3
        // 111111111111 / 111 => 1001001001

        long rem = N / g - 1;
        long res = 0;
        long x = (long)BigInteger.ModPow(10, g - 1, M);
        long added = 0;

        for (long i = 1; rem > 0; i *= 2, rem /= 2)
        {
            if (rem % 2 == 1)
            {
                res = (x * (long)BigInteger.ModPow(10, added, M) + res) % M;
                added += g * i;
            }
            x = x * (1 + (long)BigInteger.ModPow(10, g * i, M)) % M;
        }
        return (res * 10 + 1) % M;
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