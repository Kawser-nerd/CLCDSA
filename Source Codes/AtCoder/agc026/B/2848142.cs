using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
//using System.Numerics;  //comment out if AOJ
using System.Text;

using Problem = Tmp.Problem;
using MyIO;

#pragma warning disable   //for AOJ

namespace Tmp
{
    class Problem : IDisposable
    {
        bool IsGCJ;
        int Repeat;
        Scanner sc;
        Printer pr;
        public Problem(bool isGCJ, Scanner scanner, Printer printer)
        {
            sc = scanner;
            pr = printer;
            IsGCJ = isGCJ;
            if (isGCJ) Repeat = sc.nextInt();
            else Read();
        }
        public Problem(bool isGCJ) : this(isGCJ, new Scanner(), new Printer()) { }
        public Problem(bool isGCJ, Scanner scanner) : this(isGCJ, scanner, new Printer()) { }
        public Problem(bool isGCJ, Printer printer) : this(isGCJ, new Scanner(), printer) { }
        public void Solve()
        {
            if (IsGCJ) for (var i = 0; i < Repeat; i++) { Read(); pr.Write("Case #" + (i + 1) + ": "); SolveOne(); }
            else SolveOne();
        }
        public void Dispose()
        {
            sc.Dispose();
            pr.Dispose();
        }
        public int Size { get { return 1; } }
        public const long Mod = 1000000007;

        // ????????????
        // string S;
        // int a;
        int t;
        long a, b, c, d;
        /// <summary>
        /// ????????????
        /// </summary>
        void Read()
        {

        }
        /// <summary>
        /// ???????????
        /// </summary>
        void SolveOne()
        {
            t = sc.nextInt();
            for (int tt = 0; tt < t; tt++)
            {
                a = sc.nextLong();
                b = sc.nextLong();
                c = sc.nextLong();
                d = sc.nextLong();
                long g = Func.GCD(a, b);
                g = Func.GCD(g, c);
                g = Func.GCD(g, d);
                a /= g;
                b /= g;
                c /= g;
                d /= g;
                if (Judge())
                {
                    Console.WriteLine("Yes");
                }
                else
                {
                    Console.WriteLine("No");
                }
            }
        }

        bool Judge()
        {
            if (a < b || d < b)
            {
                //Console.WriteLine("a");
                return false;
            }
            if (b +1 <= c)
            {
            //    Console.WriteLine("b");

                return true;
            }
            if(a%b <= c && d%b ==0)
            {
              //  Console.WriteLine("c");

                return true;
            }

            if (c < a % b)
            {
            //    Console.WriteLine("G");
                return false;
            }
            long e = a % b;
            long f = d % b;
            long g = e + (b - e - 1) / f * f;
            if (c < g && g < b)
            {
            //    Console.WriteLine("F");
                return false;
            }
            HashSet<long> set = new HashSet<long>();
            set.Add(g);
            while (true)
            {
                e = (g + f) % b;
                g = e + (b - e - 1) / f * f;
                if(set.Contains(g))
                {
                    return true;
                }
                else
                {
                    set.Add(g);
                }
                if (c < g && g < b)
                {
                    //    Console.WriteLine("F");
                    return false;
                }
            }
            //Console.WriteLine("e");

            return true;
        }
    }
}
class Program
{
    //public static RandomSFMT rand = new RandomSFMT();
    public static bool IsJudgeMode = true;
    public static bool IsGCJMode = false;
    public static bool IsSolveCreated = true;
    static void Main()
    {
        if (IsJudgeMode)
            if (IsGCJMode) using (var problem = new Problem(true, new Scanner("C-large-practice.in.txt"), new Printer("output.txt"))) problem.Solve();
            else using (var problem = new Problem(false, new Printer())) problem.Solve();
        else
        {
            var num = 1;
            int size = 0;
            decimal time = 0;
            for (var tmp = 0; tmp < num; tmp++)
            {
                using (var P = IsSolveCreated ? new Problem(false, new Scanner("input.txt"), new Printer()) : new Problem(false))
                {
                    size = P.Size;
                    //time += Func.MeasureTime(() => P.Solve());
                }
            }
            Console.WriteLine("{0}, {1}ms", size, time / num);
        }
    }
}

/// <summary>
/// ????????IO
/// </summary>
namespace MyIO
{
    class Printer : IDisposable
    {
        bool isConsole;
        TextWriter file;
        public Printer() { file = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false }; isConsole = true; }
        public Printer(string path) { file = new StreamWriter(path, false) { AutoFlush = false }; isConsole = false; }
        public void Write<T>(T value) { file.Write(value); }
        public void Write(bool b) { file.Write(b ? "YES" : "NO"); }
        public void Write(string str, params object[] args) { file.Write(str, args); }
        public void WriteLine() { file.WriteLine(); }
        public void WriteLine<T>(T value) { file.WriteLine(value); }
        public void WriteLine(bool b) { file.WriteLine(b ? "YES" : "NO"); }
        public void WriteLine<T>(IEnumerable<T> list) { foreach (var x in list) file.WriteLine(x); }
        public void WriteLine<T>(List<T> list) { foreach (var x in list) file.WriteLine(x); }
        public void WriteLine<T>(T[] list) { foreach (var x in list) file.WriteLine(x); }
        public void WriteLine(string str, params object[] args) { file.WriteLine(str, args); }
        public void Dispose() { file.Flush(); if (!isConsole) file.Dispose(); }
    }
    class Scanner : IDisposable
    {
        bool isConsole;
        TextReader file;
        public Scanner() { file = Console.In; }
        public Scanner(string path) { file = new StreamReader(path); isConsole = false; }
        public void Dispose() { if (!isConsole) file.Dispose(); }

        #region next????
        string[] nextBuffer = new string[0];
        int BufferCnt = 0;

        char[] cs = new char[] { ' ' };

        public string next()
        {
            while (BufferCnt >= nextBuffer.Length)
            {
                string st = file.ReadLine();
                while (st == "") st = file.ReadLine();
                nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
                BufferCnt = 0;
            }
            return nextBuffer[BufferCnt++];
        }

        public int nextInt()
        {
            return int.Parse(next());
        }

        public long nextLong()
        {
            return long.Parse(next());
        }

        public double nextDouble()
        {
            return double.Parse(next());
        }

        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public string[] next(int n) { return enumerate(n, next); }
        public double[] nextDouble(int n) { return enumerate(n, nextDouble); }
        public int[] nextInt(int n) { return enumerate(n, nextInt); }
        public long[] nextLong(int n) { return enumerate(n, nextLong); }
        #endregion
    }
}


#region MyMath
static partial class Func
{
    #region BasicMath
    //TODO: ????????(extgcd??)

    /// <summary>
    /// ?????
    /// </summary>
    /// <param name="n"></param>
    /// <param name="m"></param>
    /// <returns></returns>
    public static int GCD(int n, int m)
    {
        var a = Math.Abs(n);
        var b = Math.Abs(m);
        if (a < b) { var c = a; a = b; b = c; }
        while (b > 0)
        {
            var c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    /// <summary>
    /// ?????
    /// </summary>
    /// <param name="n"></param>
    /// <param name="m"></param>
    /// <returns></returns>
    public static long GCD_oldver(long n, long m)
    {
        var a = Math.Abs(n);
        var b = Math.Abs(m);
        if (a < b) { var c = a; a = b; b = c; }
        while (b > 0)
        {
            var c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    /// <summary>
    /// ?????
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    public static long GCD(long a, long b)
    {
        var n = (ulong)Math.Abs(a); var m = (ulong)Math.Abs(b);
        if (n == 0) return (long)m; if (m == 0) return (long)n;
        int zm = 0, zn = 0;
        while ((n & 1) == 0) { n >>= 1; zn++; }
        while ((m & 1) == 0) { m >>= 1; zm++; }
        while (m != n)
        {
            if (m > n) { m -= n; while ((m & 1) == 0) m >>= 1; }
            else { n -= m; while ((n & 1) == 0) n >>= 1; }
        }
        return (long)n << Math.Min(zm, zn);
    }
    /// <summary>
    /// ?????
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    //public static BigInteger GCD(BigInteger a, BigInteger b) { return BigInteger.GreatestCommonDivisor(a, b); } //comment out if AOJ

    /// <summary>
    /// ?????
    /// </summary>
    /// <param name="n"></param>
    /// <param name="m"></param>
    /// <returns></returns>
    public static long LCM(long n, long m) { return Math.Abs((n / GCD(n, m)) * m); }

    /// <summary>
    /// n???????????? (get all primes less than or equal to n)
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    public static List<int> GetPrimes(int n)
    {
        if (n < 3) n = 3;
        var m = (n - 1) >> 1;
        var primes = new List<int>((int)(n / Math.Log(n)));
        primes.Add(2);
        var composites = new bool[m];
        composites[0] = false;
        for (var p = 0; p < m; p++)
        {
            if (!composites[p])
            {
                var pnum = 2 * p + 3;
                primes.Add(pnum);
                for (var k = 3 * p + 3; k < m; k += pnum) composites[k] = true;
            }
        }
        return primes;
    }

    #endregion

    #region Mod
    const int mod = 1000000007;

    public struct Mod
    {
        public long n;
        public Mod(long m)
        {
            n = m;
            if (n >= mod) n %= mod;
            else if (n < 0) n = (n % mod + mod) % mod;
        }

        public static explicit operator long(Mod m) { return m.n; }

        public static Mod operator +(Mod a, Mod b) { long tmp = a.n + b.n; if (tmp >= mod) tmp -= mod; return new Mod(tmp); }
        public static Mod operator -(Mod a, Mod b) { long tmp = a.n - b.n; if (tmp < mod) tmp += mod; return new Mod(tmp); }
        public static Mod operator *(Mod a, Mod b) { long tmp = ((a.n * b.n) % mod); return new Mod(tmp); }
        public static Mod operator ^(Mod a, int n)
        {
            if (n == 0) return new Mod(1);
            Mod res = (a * a) ^ (n / 2);
            if (n % 2 == 1) res = res * a;
            return res;
        }
        public static Mod operator /(Mod a, Mod b)
        {
            return a * new Mod(inv(b.n, mod));
        }
    }


    static long inv(long a, long p)
    {
        return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
    }

    const int MAX_N = 1024000;
    static bool modFact_Initialized = false;
    static Mod[] fact = new Mod[MAX_N], factinv = new Mod[MAX_N];
    static void init()
    {
        modFact_Initialized = true;
        fact[0] = new Mod(1); factinv[0] = new Mod(1);
        for (int i = 0; i < MAX_N - 1; i++)
        {
            fact[i + 1] = fact[i] * new Mod(i + 1);
            factinv[i + 1] = factinv[i] / new Mod(i + 1);
        }
    }
    /// <summary>
    /// aCb (combination, ???)
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    public static Mod comb(int a, int b)
    {
        if (modFact_Initialized == false) { init(); }
        return fact[a] * factinv[b] * factinv[a - b];
    }

    #endregion
}
#endregion