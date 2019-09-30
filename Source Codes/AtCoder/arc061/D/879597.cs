using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly int Mod = (int)1e9 + 7;

    public void Solve()
    {
        int A = Reader.Int(), B = Reader.Int(), C = Reader.Int();
        if (B > C) { int t = B; B = C; C = t; }
        long ans = 0;
        var Comb = new ModC(A + B + C, Mod);
        var pow3 = new long[A + B + C];
        pow3[0] = 1;
        for (int i = 1; i < pow3.Length; i++) pow3[i] = pow3[i - 1] * 3 % Mod;
        long BCcomb = 1;

        for (int S = A - 1; S <= A - 1 + B + C; S++)
        {
            ans = (ans + Comb[S, A - 1] * BCcomb % Mod * pow3[A + B + C - S - 1]) % Mod;
            BCcomb = BCcomb * 2 % Mod;
            int rem = S - A + 1;
            if (rem >= B) BCcomb = (BCcomb + Mod - Comb[rem, B]) % Mod;
            if (rem >= C) BCcomb = (BCcomb + Mod - Comb[rem, rem - C]) % Mod;
        }

        Console.WriteLine(ans);
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
            Fact[0] = 1;
            for (long i = 1; i <= maxN; i++)
                Fact[i] = Fact[i - 1] * i % P;
            InvFact[maxN] = ModPower(Fact[maxN], Mod - 2, Mod);
            for (int i = maxN - 1; i >= 0; i--)
                InvFact[i] = InvFact[i + 1] * (i + 1) % Mod;
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