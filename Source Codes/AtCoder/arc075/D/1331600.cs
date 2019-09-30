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
        int D = Reader.Int();
        int Dlen = (D + "").Length;
        long ans = 0;

        for (int len = Dlen; len <= Dlen * 2; len++)
            for (int mask = 0; mask < (1 << len / 2); mask++)
            {
                long count = 1;
                long rem = D;
                long p10 = (long)Math.Pow(10, len - 1);
                for (int i = 0; i < len / 2; i++, rem /= 10, p10 /= 100)
                {
                    long d = (rem % 10 + 10) % 10 - (mask >> i & 1) * 10;
                    if (d == -10) { rem = -1; break; }
                    count *= (10 - Math.Abs(d)) - (i == 0 ? 1 : 0);
                    rem -= p10 * -d + d;
                }
                if (len % 2 == 1) count *= (len == 1) ? 9 : 10;
                if (rem == 0) ans += count;
            }

        Console.WriteLine(ans);
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