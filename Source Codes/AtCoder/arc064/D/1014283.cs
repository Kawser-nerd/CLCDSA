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
    static readonly int Mod = (int)1e9 + 7;

    public void Solve()
    {
        int N = Reader.Int(), K = Reader.Int();
        long ans = 0;
        var div = Divisors(N);
        var num = new long[div.Length];

        for (int a = 0; a < div.Length; a++)
        {
            for (int b = 0; b < a; b++)
                if (div[a] % div[b] == 0)
                    num[a] -= num[b];
            long pow = ModPower(K, (div[a] + 1) / 2, Mod);
            num[a] = ((num[a] + pow) % Mod + Mod) % Mod;
            if (div[a] % 2 == 0)
                ans += num[a] * (div[a] / 2) % Mod;
            else
                ans += num[a] * div[a] % Mod;
        }

        Console.WriteLine(ans % Mod);
    }

    long ModPower(long x, long n, long mod) // x ^ n
    {
        long res = 1;
        if ((x %= mod) < 0) x += mod;
        for (; n > 0; n >>= 1, x = x * x % mod)
            if ((n & 1) == 1) res = res * x % mod;
        return res;
    }

    static int[] Divisors(int n)
    {
        var divisors = new List<int>();
        int sqrt = (int)Math.Sqrt(n);
        for (int i = 1; i <= sqrt; i++)
            if (n % i == 0)
            {
                divisors.Add(i);
                if (i * i != n) divisors.Add(n / i);
            }
        divisors.Sort();
        return divisors.ToArray();
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