using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        var S = Reader.String();
        var hash = new RollingHash(S);
        var hashrev = new RollingHash(new string(S.Reverse().ToArray()));
        long ans = 0;

        for (int i = S.Length / 2 + 1; i < S.Length - 1; i++)
        {
            int Rlen = S.Length - i;
            int A = BinarySearchMax(0, Math.Min(i - 2, Rlen - 1),
                x => hash[0, x] == hash[i, i + x]);
            int C = BinarySearchMax(0, Math.Min(i - 2, Rlen - 1),
                x => hashrev[0, x] == hashrev[Rlen, Rlen + x]);
            if (A > 0 && C > 0 && A + C >= Rlen)
                ans += A - (Rlen - C) + 1;
        }

        Console.WriteLine(ans);
    }


    // [L, R]
    int BinarySearchMax(int L, int R, Predicate<int> F)
    {
        R++;
        for (int x; R - L > 1; )
            if (F((x = L + R >> 1))) L = x;
            else R = x;
        return L;
    }
}

public class RollingHash
{
    static readonly ulong Mod0 = (ulong)4e9 + 7;
    static readonly ulong Mod1 = (ulong)4e9 + 9;
    static readonly ulong Mod2 = (ulong)4e9 + 19;
    static readonly ulong Mod3 = (ulong)4e9 + 63;
    static readonly ulong[] Mod = { Mod0, Mod1, Mod2, Mod3 };
    ulong m = 88172645463325252UL;
    ulong XorShift() { m ^= m << 13; m ^= m >> 7; return m ^= m << 17; }
    ulong XorShift(ulong min, ulong max) { return min + XorShift() % (ulong)(max - min); }

    readonly int N;
    readonly uint[][] Hash = new uint[Mod.Length][], Pow = new uint[Mod.Length][];

    public RollingHash(IEnumerable<char> A, long seed = 0)
    {
        N = A.Count();
        if (seed != 0) m = (ulong)seed;
        for (int i = 0; i < Mod.Length; i++)
            Init(XorShift((ulong)2e9, Mod[i]), Mod[i], A, ref Hash[i], ref Pow[i]);
    }

    void Init(ulong x, ulong mod, IEnumerable<char> A, ref uint[] hash, ref uint[] pow)
    {
        hash = new uint[N + 1];
        pow = new uint[N + 1];
        pow[0] = 1;
        int i = 0;
        foreach (var a in A)
        {
            hash[i + 1] = (uint)((hash[i] + (ulong)pow[i] * (ulong)a) % mod);
            pow[i + 1] = (uint)(pow[i] * x % mod);
            i++;
        }
    }

    public ulong this[int L, int R] { get { return Get(L, R); } }
    public ulong Get(int L, int R)
    {
        ulong k1, k2;
        Get2(L, R, out k1, out k2);
        return k1 ^ k2;
    }

    public void Get2(int L, int R, out ulong res1, out ulong res2)
    {
        res1 = (Sub(Hash[0][R], Hash[0][L], Mod0) * Pow[0][N - L] % Mod0 << 32) +
                Sub(Hash[1][R], Hash[1][L], Mod1) * Pow[1][N - L] % Mod1;
        res2 = (Sub(Hash[2][R], Hash[2][L], Mod2) * Pow[2][N - L] % Mod2 << 32) +
                Sub(Hash[3][R], Hash[3][L], Mod3) * Pow[3][N - L] % Mod3;
    }

    ulong Sub(ulong a, ulong b, ulong mod) { return (a >= b) ? a - b : mod + a - b; }
}


class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { Dispose(); A = new string[0]; }
    public static void Set(TextReader r) { Init(); reader = r; }
    public static void Set(string file) { Init(); reader = new StreamReader(file); }
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
    public static void Dispose() { reader.Dispose(); }
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