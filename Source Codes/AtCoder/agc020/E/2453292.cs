using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using static System.Math;
using Number = System.Int32;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {

            var s = rs;
            var dp = new HashMap<string, ModInt>();
            Func<char[], ModInt> dfs = null;
            dfs = (str) =>
            {
                if (str.Length == 0) return 1;
                var t = new string(str);
                ModInt ret = 0;
                if (dp.TryGetValue(t, out ret)) return ret;
                ret += (str[0] == '1' ? 2 : 1) * dfs(str.Skip(1).ToArray());
                for (int k = 1; k < str.Length; k++)
                {
                    var mask = new char[k];
                    for (int j = 0; j < k; j++)
                        mask[j] = '1';
                    for (int i = 0; (i + 1) * k <= str.Length; i++)
                    {
                        for (int j = 0; j < k; j++)
                            if (str[i * k + j] == '0') mask[j] = '0';
                        if (i != 0)
                        {
                            ret += dfs(mask) * dfs(str.Skip((i + 1) * k).ToArray());
                        }
                    }
                }
                //Debug.WriteLine($"{str.AsString()} {ret}");
                return dp[t] = ret;
            };
            Console.WriteLine(dfs(s.ToCharArray()));
        }

        const long INF = 5L << 60;
        static int[] dx = { -1, 0, 1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f) {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex {
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
        return string.Join(st, ie);
    }
    static public void Main() {
        Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        solver.Solve();
        Console.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO {
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer: StreamWriter {
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }

        private byte read() {
            if (isEof) return 0;
            if (ptr >= len)
            {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0)
                {
                    isEof = true;
                    return 0;
                }
            }
            return buf[ptr++];
        }

        public char Char() {
            byte b = 0;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }
        public string Scan() {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine() {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n' && b != 0; b = (char)read()) if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
        public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
        public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
    }
}

#endregion

#region ModInt
/// <summary>
/// [0,<see cref="Mod"/>) ???????????
/// </summary>
public struct ModInt {
    /// <summary>
    /// ???????
    /// </summary>
    public const long Mod = 998244353;

    /// <summary>
    /// ??????
    /// </summary>
    public long num;
    /// <summary>
    /// ?? <paramref name="n"/> ???????????????????
    /// </summary>
    /// <param name="n">??????????</param>
    /// <remarks>????????????????????????????????????<paramref name="n"/> ? [0,<see cref="Mod"/>) ??????? <paramref name="n"/> ??????????????????? O(1) ????????</remarks>
    public ModInt(long n) { num = n; }
    /// <summary>
    /// ??????????????????????
    /// </summary>
    /// <returns>[0,<see cref="Mod"/>) ???????? 10 ????????</returns>
    public override string ToString() { return num.ToString(); }
    public static ModInt operator +(ModInt l, ModInt r) { l.num += r.num; if (l.num >= Mod) l.num -= Mod; return l; }
    public static ModInt operator -(ModInt l, ModInt r) { l.num -= r.num; if (l.num < 0) l.num += Mod; return l; }
    public static ModInt operator *(ModInt l, ModInt r) { return new ModInt(l.num * r.num % Mod); }
    public static implicit operator ModInt(long n) { n %= Mod; if (n < 0) n += Mod; return new ModInt(n); }

    /// <summary>
    /// ????? 2 ?????????????????
    /// </summary>
    /// <param name="v">?????</param>
    /// <param name="k">????</param>
    /// <returns>?????????? O(N log N) ????????</returns>
    public static ModInt Pow(ModInt v, long k) { return Pow(v.num, k); }

    /// <summary>
    /// ????? 2 ?????????????????
    /// </summary>
    /// <param name="v">?????</param>
    /// <param name="k">????</param>
    /// <returns>?????????? O(N log N) ????????</returns>
    public static ModInt Pow(long v, long k) {
        long ret = 1;
        for (k %= Mod - 1; k > 0; k >>= 1, v = v * v % Mod)
            if ((k & 1) == 1) ret = ret * v % Mod;
        return new ModInt(ret);
    }
    /// <summary>
    /// ????????????????
    /// </summary>
    /// <param name="v">???????????</param>
    /// <returns>?????????</returns>
    /// <remarks>??????????????????????????????? O(log N) ???????</remarks>
    public static ModInt Inverse(ModInt v) { return Pow(v, Mod - 2); }
}
#endregion

#region HashMap<K,V>
public class HashMap<K, V>: Dictionary<K, V>
//where V : new()
{
    public HashMap() : base() { }
    public HashMap(int cap) : base(cap) { }
    new public V this[K i] {
        get {
            V v;
            return TryGetValue(i, out v) ? v :
                base[i] = default(V);
            //base[i] = new V();
        }
        set { base[i] = value; }
    }
}
#endregion