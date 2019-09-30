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
        int h, w, k, sx, sy;
        string[] map;
        int[,] count;
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
            int[] vy = { 1, 0, -1, 0 };
            int[] vx = { 0, 1, 0, -1 }; 

            h = sc.nextInt();
            w = sc.nextInt();
            k = sc.nextInt();
            map = new string[h];
            count = new int[h, w];
            
            Queue<int> qx = new Queue<int>();
            Queue<int> qy = new Queue<int>();
            Queue<int> qx2 = new Queue<int>();
            Queue<int> qy2 = new Queue<int>();

            for (int i = 0; i < h; i++)
            {
                map[i] = sc.next();
                for (int j = 0; j < w; j++)
                {
                    count[i, j] = -1;
                    if(map[i][j] =='S')
                    {
                        sy = i;
                        sx = j;
                        qy.Enqueue(sy);
                        qx.Enqueue(sx);
                        count[i, j] = 0;
                    }
                }
            }

            while(qx.Count>0)
            {
                int nowx = qx.Dequeue();
                int nowy = qy.Dequeue();

                for (int i = 0; i < 4; i++)
                {
                    int nextx = nowx + vx[i];
                    int nexty = nowy + vy[i];
                    if(inside(nexty,nextx) && count[nexty,nextx] ==-1)
                    {
                        if(map[nexty][nextx]=='.' && count[nowy, nowx] < k)
                        {
                            count[nexty, nextx] = count[nowy, nowx] + 1;
                            qx.Enqueue(nextx);
                            qy.Enqueue(nexty);
                        }
                        else
                        {
                            count[nexty, nextx] = k + 1;
                            qx2.Enqueue(nextx);
                            qy2.Enqueue(nexty);
                        }
                    }
                }
            }

            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (0 <= count[i, j] && count[i, j] <= k)
                    {
                        count[i, j] = k;
                    }
                }
            }

            while (qx2.Count > 0)
            {
                int nowx = qx2.Dequeue();
                int nowy = qy2.Dequeue();

                for (int i = 0; i < 4; i++)
                {
                    int nextx = nowx + vx[i];
                    int nexty = nowy + vy[i];
                    if (inside(nexty, nextx) && count[nexty, nextx] == -1)
                    {
                        count[nexty, nextx] = count[nowy, nowx] + 1;
                        qx2.Enqueue(nextx);
                        qy2.Enqueue(nexty);
                    }
                }
            }

            int ans = int.MaxValue;
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (i==0 || i ==h-1 || j==0 ||j==w-1)
                    {
                        ans = Math.Min(ans, count[i, j]);
                    }
                }
            }
            Console.WriteLine((ans - 1) / k + 1);
        }

        bool inside(int y, int x)
        {
            return y >= 0 && x >= 0 && y < h && x < w;
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