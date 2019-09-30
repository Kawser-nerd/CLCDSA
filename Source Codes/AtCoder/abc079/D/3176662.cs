using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.IO;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;
using static Ex;
class AC {
    /*------------------------------------------------------------------*/
    private int h, w;
    private int[,] c, a;
    void Solve() {
        io.i(out h, out w);
        io.ini(out c, 10, 10);
        io.ini(out a, h, w);
        var wf = new WarshallFloyd(10, false);
        c.Fun((i, j) => wf.AddPath(i, j, c[i, j]));
        wf.Run();
        var score = 0L;
        a.Fun((i, j) => {
            if(a[i, j] != -1)
                score += wf.MinCost(a[i, j], 1);
        });
        score.Prt();
    }
    /*------------------------------------------------------------------*/
    void Test() {
        //--- TEST ---//
    }
    public static void Main(string[] args) => new AC().Stream();
    IO io = new IO();
    private void Stream() {
        /*
        var exStdIn = new System.IO.StreamReader("stdin.txt");
        SetIn(exStdIn);
        Test();
        */
        Solve();
        io.Flush();
    }
}
class IO {
    #region INPUT
    #region FastRead    
    private const int Size = 1 << 12;
    private readonly Stream _stream = OpenStandardInput();
    private readonly byte[] _buffer = new byte[Size];
    private int _ptr = 0, _buffLen = 0;
    private bool HasNextByte() {
        if(_ptr < _buffLen) return true;
        _ptr = 0;
        _buffLen = _stream.Read(_buffer, 0, Size);
        return _buffLen > 0;
    }
    private byte ReadByte() {
        if(HasNextByte()) return _buffer[_ptr++];
        else
        //input??????????error
            throw new EndOfStreamException();
    }
    private bool IsAscii(int c) => '!' <= c && c <= '~';
    private char NextChar() {
        var b = ReadByte();
        while(!IsAscii(b)) b = ReadByte();
        return (char)b;
    }
    private string Next() {
        var sb = new StringBuilder();
        for(var b = NextChar(); IsAscii(b); b = (char)ReadByte()) sb.Append(b);
        return sb.ToString();
    }
    public string String => Next();
    public char Char => NextChar();
    public int Int => int.Parse(Next());
    public long Long => long.Parse(Next());
    public double Double => double.Parse(Next());
    #endregion
    #region LazyRead        
    private void scan <T>(ref T x) {
        if(x is int) __refvalue(__makeref(x),int) = int.Parse(Next());
        else if(x is long) __refvalue(__makeref(x),long) = long.Parse(Next());
        else if(x is double) __refvalue(__makeref(x),double) = double.Parse(Next());
        else if(x is char) __refvalue(__makeref(x),char) = NextChar();
        else __refvalue(__makeref(x),string) = Next();
    }
    public void i <T>(out T t) {
        t = default(T);
        scan(ref t);
    }
    public void i <T, TU>(out T t, out TU u) {
        i(out t);
        i(out u);
    }
    public void i <T, TU, TV>(out T t, out TU u, out TV v) {
        i(out t, out u);
        i(out v);
    }
    public void i <T, TU, TV, TW>(out T t, out TU u, out TV v, out TW w) {
        i(out t, out u);
        i(out v, out w);
    }
    public void i <T, TU, TV, TW, TX>(out T t, out TU u, out TV v, out TW w, out TX x) {
        i(out t, out u, out v);
        i(out w, out x);
    }
    public void i <T, TU, TV, TW, TX, TY>(out T t, out TU u, out TV v, out TW w, out TX x, out TY y) {
        i(out t, out u, out v);
        i(out w, out x, out y);
    }
    public void ini <T>(out T[] a, int n) {
        a = new T[n];
        for(int i = 0; i < n; ++i) i <T>(out a[i]);
    }
    public void ini <T, TU>(out T[] a, out TU[] b, int n) {
        a = new T[n];
        b = new TU[n];
        for(int i = 0; i < n; ++i) i <T, TU>(out a[i], out b[i]);
    }
    public void ini <T, TU, TV>(out T[] a, out TU[] b, out TV[] c, int n) {
        a = new T[n];
        b = new TU[n];
        c = new TV[n];
        for(var i = 0; i < n; ++i) i <T, TU, TV>(out a[i], out b[i], out c[i]);
    }
    public void ini <T>(out T[,] a, int h, int w) {
        a = new T[h, w];
        for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) i <T>(out a[i, j]);
    }
    #endregion
    #endregion
    #region OUTPUT
    private readonly StreamWriter _sw = new StreamWriter(OpenStandardOutput()) {
#if DEBUG
        AutoFlush = true
#else
        AutoFlush = false
#endif
    };
    public void Flush() => Out.Flush();
    public void YN(bool f) => WriteLine(f ? "YES" : "NO");
    public void Yn(bool f) => WriteLine(f ? "Yes" : "No");
    public void yn(bool f) => WriteLine(f ? "yes" : "no");
    #endregion
    public IO() { SetOut(_sw); }
}
static class Ex {
    #region ??????         
    public static void LOG <T>(T x, [CallerLineNumber] int line = 0) => Error.WriteLine($"--- LOG[{line}]: {x} ---");
    public static void FOR(int a, int b, Action <int> f) => FOR(a, b, 1, f);
    public static void FOR(int a, int b, int n, Action <int> f) {
        for(int i = a; i < b; i += n) f(i);
    }
    public static void REP(int a, Action <int> f) => FOR(0, a, f);
    public static void REPEQ(int a, Action <int> f) => FOR(0, a + 1, f);
    public static void FOREQ(int a, int b, Action <int> f) => FOR(a, b + 1, f);
    public static void FOREQ(int a, int b, int n, Action <int> f) => FOR(a, b + 1, n, f);
    public static void REP(int a, int b, Action <int, int> f) => REP(a, i => REP(b, j => f(i, j)));
    public static void REP(int a, int b, int c, Action <int, int, int> f) => REP(a, i => REP(b, j => REP(c, k => f(i, j, k))));
    public static void REPEQ(int a, int b, Action <int, int> f) => REPEQ(a, i => REPEQ(b, j => f(i, j)));
    public static void REPEQ(int a, int b, int c, Action <int, int, int> f) => REPEQ(a, i => REPEQ(b, j => REPEQ(c, k => f(i, j, k))));
    public static T MIN <T>(params T[] xs) => xs.Min();
    public static T MAX <T>(params T[] xs) => xs.Max();
    public static IEnumerable <int> RANGE(int s, int e) => Enumerable.Range(s, e - s + 1);
    public static int LCM(int a, int b) => a * (b / GCD(a, b));
    public static int GCD(int a, int b) => (a < b) ? GCD(b, a) : b == 0 ? a : GCD(b, a % b);
    public static int LCM(params int[] xs) => xs.Aggregate(LCM);
    public static int GCD(params int[] xs) => xs.Aggregate(GCD);
    public static long LCM(long a, long b) => a * (b / GCD(a, b));
    public static long GCD(long a, long b) => (a < b) ? GCD(b, a) : b == 0L ? a : GCD(b, a % b);
    public static long LCM(params long[] xs) => xs.Aggregate(LCM);
    public static long GCD(params long[] xs) => xs.Aggregate(GCD);
    #endregion
    #region ??????        
    public static void Rep(this int x, Action <int> f) => REP(x, f);
    public static void RepEq(this int x, Action <int> f) => REPEQ(x, f);
    public static int ToInt(this string s) {
        double n;
        double.TryParse(s.TrimStart('0'), out n);
        return Convert.ToInt32(n);
    }
    public static int ToInt(this char c) => ToInt(c.ToString());
    public static int ToInt(this char[] c) => ToInt(new string(c));
    public static long ToLong(this string s) {
        double n;
        double.TryParse(s.TrimStart('0'), out n);
        return Convert.ToInt64(n);
    }
    public static long ToLong(this char c) => ToLong(c.ToString());
    public static long ToLong(this char[] c) => ToLong(new string(c));
    public static void Do <T>(this T x, Action <T> f) => f(x);
    public static TU Then <T, TU>(this T x, Func <T, TU> f) => f(x);
    public static void Fun <T>(this T[] xs, Action <int> f) => REP(xs.Length, f);
    public static void Fun <T>(this T[,] xxs, Action <int, int> f) => REP(xxs.GetLength(0), i => REP(xxs.GetLength(1), j => f(i, j)));
    public static bool IsIn <T>(this T[] xs, int i) => 0 <= i && i < xs.Length;
    public static bool IsIn <T>(this T[,] xxs, int i, int j) => 0 <= i && i < xxs.GetLength(0) && 0 <= j && j < xxs.GetLength(1);
    public static void Iter <T>(this IEnumerable <T> xs, Action <T> f) {
        foreach(var x in xs) f(x);
    }
    public class IndexedItem <T> {
        public int Idx;
        public T Val;
        public IndexedItem(int idx, T val) {
            Idx = idx;
            Val = val;
        }
    }
    public static IEnumerable <IndexedItem <T>> Indexed <T>(this IEnumerable <T> xs) => xs.Select((x, i) => new IndexedItem <T>(i, x));
    public static void Set <T>(this T[] xs, T v) => REP(xs.Length, i => xs[i] = v);
    public static void Set <T>(this T[,] xxs, T v) => REP(xxs.GetLength(0), i => REP(xxs.GetLength(1), j => xxs[i, j] = v));
    public static T[] Sort <T>(this T[] xs) {
        Array.Sort(xs);
        return xs;
    }
    public static T[] SortR <T>(this T[] xs) {
        Array.Reverse(xs.Sort());
        return xs;
    }
    public static string Pad0 <T>(this T s, int n) => s.ToString().PadLeft(n, '0');
    public static int RoundOff(this double v, int n) => (int)Round(v, n - 1, MidpointRounding.AwayFromZero);
    public static int RoundUp(this double v) => (int)Ceiling(v);
    public static int RoundDown(this double v) => (int)Floor(v);
    public static bool Odd(this int v) => (v & 1) != 0;
    public static bool Odd(this long v) => (v & 1) != 0;
    public static bool Eve(this int v) => !v.Odd();
    public static bool Eve(this long v) => !v.Odd();
    public static void Prt <T>(this T x) => WriteLine(x);
    public static void Prt <T>(this T[] xs) => xs.Iter(x => WriteLine(x));
    public static void Prt <T>(this List <T> xs) => xs.Iter(x => WriteLine(x));
    public static void Prt <T>(this T[,] xs) => xs.GetLength(0).Rep(i => {
        xs.GetLength(1).Rep(j => Write($"{xs[i, j]} "));
        WriteLine();
    });
    public static void Prt_ <T>(this T[] xs) => WriteLine(string.Join(" ", xs));
    public static void Log <T>(this T x, [CallerLineNumber] int line = 0) => Error.WriteLine($"--- LOG[{line}]: {x} ---");
    public static void Log <T>(this T[] xs, [CallerLineNumber] int line = 0) {
        Error.WriteLine($"^^^ LOG[{line}] ^^^");
        xs.Iter(x => Error.WriteLine(x));
        Error.WriteLine($"vvv LOG[{line}] vvv");
    }
    public static void Log <T>(this T[,] xs, [CallerLineNumber] int line = 0) {
        Error.WriteLine($"^^^ LOG[{line}] ^^^");
        xs.GetLength(0).Rep(i => {
            xs.GetLength(1).Rep(j => Error.Write($"{xs[i, j]} "));
            Error.WriteLine();
        });
        Error.WriteLine($"vvv LOG[{line}] vvv");
    }
    public static string Reversed(this string s) => string.Join("", s.Reverse());
    public static string Repeat(this string s, int n) => string.Concat(Enumerable.Repeat(s, n).ToArray());
    #endregion
}
class WarshallFloyd {
    bool IsNonDir;
    int VertexNum;
    int EdgeNum;
    long INF;
    long[,] G;
    public WarshallFloyd(int n, bool isNondir = true, long inf = long.MaxValue / 2) {
        IsNonDir = isNondir;
        INF = inf;
        Init(n);
    }
    public void Init(int n) {
        VertexNum = n;
        G = new long[VertexNum + 1, VertexNum + 1];
        for(int i = 0; i < VertexNum + 1; ++i)
            for(int j = 0; j < VertexNum + 1; ++j)
                G[i, j] = INF;
        for(int i = 0; i < VertexNum + 1; ++i)
            G[i, i] = 0;
    }
    public void AddPath(int f, int t, long c = 1) {
        EdgeNum++;
        G[f, t] = Math.Min(G[f, t], c);
        if(IsNonDir) G[t, f] = Math.Min(G[t, f], c);
    }
    public virtual void AddPath(int[] f, int[] t) {
        for(int i = 0; i < f.Length; ++i) AddPath(f[i], t[i]);
    }
    public virtual void AddPath(int[] f, int[] t, long[] c) {
        for(int i = 0; i < f.Length; ++i) AddPath(f[i], t[i], c[i]);
    }
    public void Run() {
        for(int i = 0; i < VertexNum + 1; ++i)
            for(int j = 0; j < VertexNum + 1; ++j)
                for(int k = 0; k < VertexNum + 1; ++k)
                    G[j, k] = Math.Min(G[j, k], G[j, i] + G[i, k]);
    }
    public long MinCost(int f, int t) => G[f, t];
}