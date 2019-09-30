using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;  //comment out if AOJ
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
            int n = sc.nextInt();
            long[] a = sc.nextLong(3 * n);
            long[] bef = new long[n + 1];
            long[] aft = new long[n + 1];

            PriorityQueue<long> px = new PriorityQueue<long>();
            PriorityQueue<long> py = new PriorityQueue<long>(CompareAccount);
            for (int i = 0; i < n; i++)
            {
                px.Enqueue(a[i]);
                py.Enqueue(a[3 * n - 1 - i]);
                bef[0] += a[i];
                aft[n] += a[3 * n - 1 - i];
            }

            for (int i = 0; i < n; i++)
            {
                px.Enqueue(a[n + i]);
                bef[i + 1] = bef[i] + a[n + i] - px.Dequeue();

                py.Enqueue(a[2 * n - 1 - i]);
                aft[n - 1 - i] = aft[n - i] + a[2 * n - 1 - i] - py.Dequeue();
            }

            long ans = long.MinValue;
            for (int i = 0; i <= n; i++)
            {
                ans = Math.Max(ans, bef[i] - aft[i]);
            }


            Console.WriteLine(ans);
        }

        // PriorityQueue ?????????????
        int CompareAccount(long x, long y)
        {
            if (x > y)
                return -1; // x?y?????
            else if (x < y)
                return 1; // x?y?????
            else // if (x == y)
                return 0; // x?y????
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

class PriorityQueue<T>
{
    private readonly List<T> heap;
    private readonly Comparison<T> compare;
    private int size;
    public PriorityQueue() : this(Comparer<T>.Default) { }
    public PriorityQueue(IComparer<T> comparer) : this(16, comparer.Compare) { }
    public PriorityQueue(Comparison<T> comparison) : this(16, comparison) { }
    public PriorityQueue(int capacity, Comparison<T> comparison)
    {
        this.heap = new List<T>(capacity);
        this.compare = comparison;
    }
    public void Enqueue(T item)
    {
        this.heap.Add(item);
        var i = size++;
        while (i > 0)
        {
            var p = (i - 1) >> 1;
            if (compare(this.heap[p], item) <= 0)
                break;
            this.heap[i] = heap[p];
            i = p;
        }
        this.heap[i] = item;

    }
    public T Dequeue()
    {
        var ret = this.heap[0];
        var x = this.heap[--size];
        var i = 0;
        while ((i << 1) + 1 < size)
        {
            var a = (i << 1) + 1;
            var b = (i << 1) + 2;
            if (b < size && compare(heap[b], heap[a]) < 0) a = b;
            if (compare(heap[a], x) >= 0)
                break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        heap.RemoveAt(size);
        return ret;
    }
    public T Peek() { return heap[0]; }
    public int Count { get { return size; } }
    public bool Any() { return size > 0; }
}