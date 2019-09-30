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
    static void Add(ref int a, int b) { if ((a += b) >= Mod) a -= Mod; }

    public void Solve()
    {
        int N = Reader.Int();
        var table = Reader.IntTable(N);
        int MaxVal = table.Max(t => Math.Max(t[0], t[1]));
        var dp = new int[MaxVal * 2 + 2, MaxVal * 2 + 2];

        foreach (var t in table)
            dp[MaxVal - t[0], MaxVal - t[1]]++;
        for (int a = 0; a <= MaxVal * 2; a++)
            for (int b = 0; b <= MaxVal * 2; b++)
            {
                Add(ref dp[a + 1, b], dp[a, b]);
                Add(ref dp[a, b + 1], dp[a, b]);
            }
        var C = new ModC(MaxVal * 4, Mod);
        long ans = 0;
        foreach (var t in table)
        {
            ans += dp[t[0] + MaxVal, t[1] + MaxVal];
            ans -= C[(t[0] + t[1]) * 2, t[0] * 2];
        }
        ans = (ans % Mod * ModPower(2, Mod - 2, Mod) % Mod + Mod) % Mod;

        Console.WriteLine(ans);
    }


    static long ModPower(long x, long n, long mod) // x ^ n
    {
        long res = 1;
        while (n > 0)
        {
            if ((n & 1) == 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

    class ModC
    {
        readonly long P;
        readonly long[] Fact, InvFact;

        public int this[int n, int k]
        {
            get
            {
                if (n < 0 || k < 0 || k > n) return 0;
                return (int)(Fact[n] * InvFact[k] % P * InvFact[n - k] % P);
            }
        }
        public ModC(int maxN, int p) // maxN < p, p is prime
        {
            P = p;
            Fact = new long[maxN + 1];
            InvFact = new long[maxN + 1];
            Fact[0] = InvFact[0] = 1;
            for (long i = 1; i <= maxN; i++)
            {
                Fact[i] = Fact[i - 1] * i % P;
                InvFact[i] = ModPower(Fact[i], P - 2, P) % P;
            }
        }
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
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()); return r; }
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