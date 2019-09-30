using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.Numerics;
using System.IO;
public class CodeForces
{
#if TEST
// To set this go to Project -> Properties -> Build -> General -> Conditional compilation symbols: -> enter 'TEST' into text box.
const bool testing = true;
#else
    const bool testing = false;
#endif


    struct Node : IComparable
    {
        public long T { get; set; }
        public long Q { get; set; }
        public int CompareTo(object obj)
        {
            return this.T.CompareTo(((Node)obj).T);
        }
    }
    public static long nPr(int n, int r)
    {
        // naive: return Factorial(n) / Factorial(n - r);
        return FactorialDivision(n, n - r);
    }
    private static long FactorialDivision(int topFactorial, int divisorFactorial)
    {
        long result = 1;
        for (int i = topFactorial; i > divisorFactorial; i--)
            result *= i;
        return result;
    }
    private static long Factorial(int i)
    {
        if (i <= 1)
            return 1;
        return i * Factorial(i - 1);
    }
    public static long nCr(int n, int r)
    {
        // naive: return Factorial(n) / Factorial(r) * Factorial(n - r);
        return nPr(n, r) / Factorial(r);
    }

    private static int LowerBound<T>(IList<T> list, T value)
    {
        if (list == null)
            throw new ArgumentNullException("list");
        var comp = Comparer<T>.Default;
        int lo = 0, hi = list.Count - 1;
        while (lo < hi)
        {
            int m = (hi + lo) / 2;  // this might overflow; be careful.
            if (comp.Compare(list[m], value) < 0) lo = m + 1;
            else hi = m - 1;
        }
        if (comp.Compare(list[lo], value) < 0) lo++;
        return Math.Min(lo, list.Count);
    }
    public class SegmentTree<T>
    {
        private int Mid;
        private T[] t;
        private Func<T, T, T> f;
        private T defaultValue = default(T);

        public SegmentTree(T[] a, T defaultValue, Func<T, T, T> f)
        {
            this.defaultValue = defaultValue;
            this.Mid = 1;
            while (Mid < a.Length) Mid *= 2;
            this.t = new T[Mid + Mid];
            this.f = f;

            Array.Copy(a, 0, this.t, Mid, a.Length);
            for (int i = Mid + a.Length; i < this.t.Length; i++) this.t[i] = this.defaultValue;
            for (int i = Mid - 1; i > 0; i--) this.UpdateValueFor(i);
        }
        public SegmentTree(T defaultValue, int capacity, Func<T, T, T> f)
        {
            this.defaultValue = defaultValue;
            this.Mid = 1;
            while (Mid < capacity) Mid *= 2;
            this.t = new T[Mid + Mid];
            this.f = f;

            for (int i = 0; i < Mid; i++)
                this.t[Mid + i] = defaultValue;

            for (int i = (Mid + Mid - 1) / 2; i > 0; i--) this.UpdateValueFor(i);
        }

        public T GetRoot()
        {
            return t[1];
        }

        public T Get(int l, int r)
        {
            l += Mid;
            r += Mid;

            T ans = this.defaultValue;
            while (l <= r)
            {
                if ((l & 1) == 1) ans = this.f(ans, t[l]);
                if ((r & 1) == 0) ans = this.f(ans, t[r]);

                l = (l + 1) >> 1;
                r = (r - 1) >> 1;
            }

            return ans;
        }

        public void Update(int i, T value)
        {
            t[i + Mid] = value;
            for (i = (i + Mid) >> 1; i >= 1; i = (i >> 1)) this.UpdateValueFor(i);
        }

        private void UpdateValueFor(int i)
        {
            t[i] = this.f(t[i + i], t[i + i + 1]);
        }
    }
    static void program(TextReader input)
    {
        
    }

    public static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine().TrimEnd());
        var all = new List<long>();
        var a = Console.ReadLine().TrimEnd().Split(' ').Select(long.Parse).ToList();
        var b = Console.ReadLine().TrimEnd().Split(' ').Select(long.Parse).ToList();
        var c = Console.ReadLine().TrimEnd().Split(' ').Select(long.Parse).ToList();
        a.Sort();
        b.Sort();
        c.Sort();
        var cNumber = new int[n];
        var aNumber = new int[n];
        var ci = 0;
        for (var i = 0; i < n; i++)
        {
            var bn = b[i];
            while (ci < n && c[ci] <= bn)
            {
                ci++;
            }
            cNumber[i] = n-ci;
        }

        var ai = 0;
        for (var i = 0; i < n; i++)
        {
            var bn = b[i];
            while (ai < n && a[ai] < bn)
            {
                ai++;
            }
            aNumber[i] = ai;
        }

        BigInteger result = 0;
        for (var i = 0; i < n; i++)
        {
            result += new BigInteger(aNumber[i]) * new BigInteger(cNumber[i]);
        }

        Console.WriteLine(result);

    }
}