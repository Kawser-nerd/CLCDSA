using System;
using System.Collections;
using System.Collections.Generic;
using System.Dynamic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection.Emit;
using System.Runtime.Remoting.Proxies;
using System.Text;
using static System.Console;
using static System.Math;
using static Ex;
using static ArrayEx;
class AC {
    /*------------------------------------------------------------------*/
    private int N, C;
    private int[,] D, c;
    void Solve() {
        io.i(out N, out C);
        io.ini(out D, C, C);
        io.ini(out c, N, N);
        c = c.To0Indexed();
        var cnt = new int[3, 30];
        REP(N, i => REP(N, j => cnt[(i + 1 + j + 1) % 3, c[i, j]]++));
        var ans = int.MaxValue;
        REP(C, i => REP(C, j => {
            if(i != j) {
                REP(C, k => {
                    if(i != k && j != k) {
                        var curCost = 0;
                        REP(C, l => curCost += D[l, i] * cnt[0, l]);
                        REP(C, l => curCost += D[l, j] * cnt[1, l]);
                        REP(C, l => curCost += D[l, k] * cnt[2, l]);
                        ans = Min(ans, curCost);
                    }
                });
            }
        }));
        io.o(ans);
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
#region OTHER
class IO {
    #region INPUT
    private const int Size = 1 << 12;
    private readonly Stream _stream = OpenStandardInput();
    private readonly byte[] _buffer = new byte[Size];
    private int _ptr = 0, _buffLen = 0;
    private bool HasNextByte() {
        if(_ptr < _buffLen)
            return true;
        _ptr = 0;
        _buffLen = _stream.Read(_buffer, 0, Size);
        return _buffLen > 0;
    }
    private byte ReadByte() {
        if(HasNextByte())
            return _buffer[_ptr++];
        else
        //input??????????error
            throw new EndOfStreamException();
    }
    private bool IsAscii(int c) => '!' <= c && c <= '~';
    private char NextChar() {
        byte b = 0;
        do
            b = ReadByte(); while(!IsAscii(b));
        return (char)b;
    }
    private string Next() {
        var sb = new StringBuilder();
        for(var b = NextChar(); IsAscii(b); b = (char)ReadByte())
            sb.Append(b);
        return sb.ToString();
    }
    private void Read <T>(out T v) => v = SuitType <T>(Next());
    private bool TypeEqual <T, TU>() => typeof(T) == typeof(TU);
    private T SuitType <T>(string s) {
        if(TypeEqual <T, int>())
            ConvertType <T, int>(int.Parse(s));
        if(TypeEqual <T, long>())
            ConvertType <T, long>(long.Parse(s));
        if(TypeEqual <T, double>())
            ConvertType <T, double>(double.Parse(s));
        if(TypeEqual <T, char>())
            ConvertType <T, char>(char.Parse(s));
        return ConvertType <T, string>(s);
    }
    private T i <T>() => SuitType <T>(String);
    public string String => Next();
    public char Char => NextChar();
    public int Int => int.Parse(Next());
    public long Long => long.Parse(Next());
    public double Double => double.Parse(Next());
    public void i <T>(out T v) => Read(out v);
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
        for(int i = 0; i < n; ++i)
            a[i] = i <T>();
    }
    public void ini <T, TU>(out T[] a, out TU[] b, int n) {
        a = new T[n];
        b = new TU[n];
        for(int i = 0; i < n; ++i) {
            a[i] = i <T>();
            b[i] = i <TU>();
        }
    }
    public void ini <T, TU, TV>(out T[] a, out TU[] b, out TV[] c, int n) {
        a = new T[n];
        b = new TU[n];
        c = new TV[n];
        for(int i = 0; i < n; ++i) {
            a[i] = i <T>();
            b[i] = i <TU>();
            c[i] = i <TV>();
        }
    }
    public void ini <T>(out T[,] a, int h, int w) {
        a = new T[h, w];
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j)
                a[i, j] = i <T>();
    }
    #endregion
    #region OUTPUT
    private readonly StreamWriter _sw = new StreamWriter(OpenStandardOutput()) {
#if DEBUG
        AutoFlush = true
#else
        AutoFlush = false
#endif
    };
    public void Flush() => Console.Out.Flush();
    public void o(params Object[] xs) => Print(false, xs);
    public void o_(params Object[] xs) => Print(true, xs);
    private void Print(bool isOneLine, params Object[] xs) {
        foreach(var x in xs) {
            if(x is int[])
                PrintArr <int>(isOneLine, x);
            else if(x is long[])
                PrintArr <int>(isOneLine, x);
            else if(x is double[])
                PrintArr <int>(isOneLine, x);
            else if(x is char[])
                PrintArr <int>(isOneLine, x);
            else if(x is string[])
                PrintArr <int>(isOneLine, x);
            else if(x is bool[])
                PrintArr <int>(isOneLine, x);
            else if(x is int[,])
                PrintArr2D(ConvertType <int[,], object>(x));
            else if(x is long[,])
                PrintArr2D(ConvertType <long[,], object>(x));
            else if(x is double[,])
                PrintArr2D(ConvertType <double[,], object>(x));
            else if(x is char[,])
                PrintArr2D(ConvertType <char[,], object>(x));
            else if(x is string[,])
                PrintArr2D(ConvertType <string[,], object>(x));
            else if(x is bool[,])
                PrintArr2D(ConvertType <bool[,], object>(x));
            else
                WriteLine(x);
        }
    }
    private void PrintArr2D <T>(T[,] a) {
        int a0 = a.GetLength(0), a1 = a.GetLength(1);
        for(int i = 0; i < a0; ++i) {
            for(int j = 0; j < a1 - 1; ++j)
                Write(a[i, j] + " ");
            WriteLine(a[i, a1 - 1]);
        }
    }
    private void PrintArr <T>(bool isOneLine, Object xs) {
        if(isOneLine)
            PrintArr1D_(ConvertType <T[], object>(xs));
        else
            PrintArr1D(ConvertType <T[], object>(xs));
    }
    private void PrintArr1D <T>(T[] xs) {
        foreach(var x in xs)
            WriteLine(x);
    }
    private void PrintArr1D_ <T>(T[] xs) => WriteLine(string.Join(" ", xs));
    public void YN(bool f) => WriteLine(f ? "YES" : "NO");
    public void Yn(bool f) => WriteLine(f ? "Yes" : "No");
    public void yn(bool f) => WriteLine(f ? "yes" : "no");
    #endregion
    private T ConvertType <T, TU>(TU v) => (T)Convert.ChangeType(v, typeof(T));
    public IO() { SetOut(_sw); }
}
static class Ex {
    public static void REP(int a, Action <int> act) => FOR(0, a, act);
    public static void FOR(int a, int b, Action <int> act) => FOR(a, b, 1, act);
    public static void FOR(int a, int b, int n, Action <int> act) {
        for(int i = a; i < b; i += n)
            act(i);
    }
    public static void REPEQ(int a, Action <int> act) => FOR(0, a + 1, act);
    public static void FOREQ(int a, int b, Action <int> act) => FOR(a, b + 1, act);
    public static void FOREQ(int a, int b, int n, Action <int> act) => FOR(a, b + 1, n, act);
    public static T MIN <T>(params T[] a) => a.Min();
    public static T MAX <T>(params T[] a) => a.Max();
}
static class NumEx {
    public static string toString(this double d) => d.ToString("R");
    public static string Pad0 <T>(this T s, int n) => s.ToString().PadLeft(n, '0');
    public static int RoundOff(this double v, int n) => (int)Round(v, n - 1, MidpointRounding.AwayFromZero);
    public static int RoundUp(this double v) => (int)Ceiling(v);
    public static int RoundDown(this double v) => (int)Floor(v);
    public static bool Odd(this int v) => (v & 1) != 0;
    public static bool Odd(this long v) => (v & 1) != 0;
}
static class ArrayEx {
    public static void SET <T>(this T[] a, T v) {
        for(int i = 0; i < a.Length; ++i)
            a[i] = v;
    }
    public static void SET <T>(this T[,] a, T v) {
        for(int i = 0; i < a.GetLength(0); ++i)
            for(int j = 0; j < a.GetLength(1); ++j)
                a[i, j] = v;
    }
    public static IEnumerable <T> UNFOLD <T>(Func <int, T> func) => UNFOLD(0, func);
    public static IEnumerable <T> UNFOLD <T>(int s, Func <int, T> func) {
        while(true)
            yield return func(s++);
    }
    public static void ITER <T>(this IEnumerable <T> xs, Action <T> act) {
        foreach(var x in xs)
            act(x);
    }
    public static int[] To0Indexed(this int[] xs) => xs.Select(x => x - 1).ToArray();
    public static int[,] To0Indexed(this int[,] xs) {
        var ys = xs;
        for(var i = 0; i < ys.GetLength(0); ++i)
            for(var j = 0; j < ys.GetLength(1); ++j)
                ys[i, j]--;
        return ys;
    }
}
#endregion