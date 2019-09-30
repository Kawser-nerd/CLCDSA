
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;
using kp.Algo;

namespace CodeJam
{
    class Solution
    {
        private const bool IsTestingRun = false;
        private const string InputFile = @"C:\Users\kp\Downloads\C-Small-attempt0.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2016 2\C.cs" + ".output.txt";
        private const bool UseMultiThreading = false;

        int rows, cols;
        int[] p;
        int[,] ans;

        void ReadData()
        {
            rows = NextInt();
            cols = NextInt();
            p = new int[2 * (rows + cols)];
            for (int i = 0; i < p.Length; i++)
            {
                p[i] = NextInt();
            }
        }

        int[,] a;

        void Solve()
        {
            ans = null;
            a = new int[rows, cols];
            Go(0, 0);
        }

        void Go(int r, int c)
        {
            if (ans != null)
                return;
            if (r == rows)
            {
                if (Ok())
                {
                    ans = new int[rows, cols];
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
                        {
                            ans[i, j] = a[i, j];
                        }
                    }
                }
                return;
            }
            if (c == cols)
            {
                Go(r + 1, 0);
                return;
            }
            Go(r, c + 1);
            a[r, c] = 1;
            Go(r, c + 1);
            a[r, c] = 0;
        }

        private bool Ok()
        {
            var need = new int[2 * (rows + cols) + 1];
            for (int i = 0; i < p.Length; i += 2)
            {
                need[p[i]] = p[i + 1];
                need[p[i + 1]] = p[i];
            }
            var was = new bool[2 * rows + 1, 2 * cols + 1];
            for (int i = 1; i <= 2 * (rows + cols); ++i)
            {
                var tt = GetCoords(i);
                var ee = GetCoords(need[i]);

                if (was[tt.Item1, tt.Item2]) continue;

                if (was[ee.Item1, ee.Item2])
                    return false;

                var q = new Queue<int>();
                q.Enqueue(tt.Item1); q.Enqueue(tt.Item2);
                was[tt.Item1, tt.Item2] = true;
                while (q.Any())
                {
                    var r = q.Dequeue();
                    var c = q.Dequeue();

                    if (r == 0 || c == 0 || r == 2 * rows || c == 2 * cols)
                    {
                        if (GetNum(r, c) != need[i] && GetNum(r, c) != i) return false;
                    }

                    for (int dr = -1; dr < 2; dr++)
                    {
                        for (int dc = -1; dc < 2; dc++)
                        {
                            if (dr == 0 || dc == 0) continue;
                            var nr = r + dr;
                            var nc = c + dc;
                            if (Can(r, c, nr, nc) && !was[nr, nc])
                            {
                                was[nr, nc] = true;
                                q.Enqueue(nr);
                                q.Enqueue(nc);
                            }
                        }
                    }
                }

                if (!was[ee.Item1, ee.Item2])
                    return false;
            }

            return true;
        }

        int GetNum(int r, int c)
        {
            if (r == 0)
            {
                return c / 2 + 1;
            }
            if (c == 2 * cols)
            {
                return r / 2 + cols + 1;
            }
            if (r == 2 * rows)
            {
                return 2 * cols + rows - (c / 2);
            }

            return 2 * cols + 2 * rows - (r / 2);
        }

        Tuple<int, int> GetCoords(int num)
        {
            if (num <= cols)
                return new Tuple<int, int>(0, 2 * num - 1);
            if (num <= cols + rows)
                return new Tuple<int, int>(2 * (num - cols) - 1, 2 * cols);
            if (num <= cols + rows + cols)
                return new Tuple<int, int>(2 * rows, 2 * cols - (2 * (num - cols - rows) - 1));
            return new Tuple<int, int>(2 * rows - (2 * (num - rows - 2 * cols) - 1), 0);
        }

        private bool Can(int r, int c, int nr, int nc)
        {
            if (nr < 0 || nr > 2 * rows || nc < 0 || nc > 2 * cols) return false;

            var rr = Math.Min(r, nr) / 2;
            var cc = Math.Min(c, nc) / 2;
            if (a[rr, cc] == 0)
            {
                return ((r < nr && c < nc) || (r > nr && c > nc));
            }
            else
            {
                return !((r < nr && c < nc) || (r > nr && c > nc));
            }
        }

        void WriteAnswer()
        {
            Out.WriteLine();
            if (ans == null)
            {
                Out.WriteLine("IMPOSSIBLE");
            }
            else
            {
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        Out.Write(ans[i, j] == 0 ? "\\" : "/");
                    }
                    Out.WriteLine();
                }
            }
        }

        #region ...

        void run()
        {
            if (IsTestingRun)
            {
                _inputStream = File.OpenText("input.txt");
                _outputStream = Console.Out;
            }
            else
            {
                _inputStream = File.OpenText(Path.Combine(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "Downloads"), InputFile));
                _outputStream = File.CreateText(Path.Combine(new FileInfo(GetType().Assembly.Location).Directory.Parent.Parent.Parent.FullName, OutputFile));
            }

            int testsCount = int.Parse(_inputStream.ReadLine());
            var solvers = new Solution[testsCount];
            for (int i = 0; i < testsCount; ++i)
            {
                solvers[i] = new Solution();
                solvers[i].ReadData();
            }

            int done = 0;
            if (UseMultiThreading)
            {
                solvers.AsParallel().WithDegreeOfParallelism(Environment.ProcessorCount).ForAll(
                    solver => { solver.Solve(); Console.Title = (++done).ToString() + " of " + testsCount; });
            }
            else
            {
                for (int i = 0; i < testsCount; ++i)
                {
                    solvers[i].Solve();
                    Console.Title = (++done).ToString() + " of " + testsCount;
                }
            }
            for (int i = 0; i < testsCount; ++i)
            {
                Out.Write(string.Format("Case #{0}: ", i + 1));
                solvers[i].WriteAnswer();
            }
            Out.Flush();
            Out.Close();
            if (IsTestingRun)
            {
                Console.WriteLine("ALL DONE!");
                Console.ReadLine();
            }
        }

        static TextWriter Out { get { return _outputStream; } }

        private static TextReader _inputStream;
        private static TextWriter _outputStream;

        public BigInteger NextBigInteger()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return BigInteger.Parse(token);
        }

        public double NextDouble()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return double.Parse(token, CultureInfo.InvariantCulture);
        }

        public long NextLong()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return long.Parse(token);
        }

        public int NextInt()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return int.Parse(token);
        }

        private static readonly Queue<string> Tokens = new Queue<string>();
        public string NextToken()
        {
            if (Tokens.Count > 0)
            {
                return Tokens.Dequeue();
            }
            while (Tokens.Count == 0)
            {
                var line = _inputStream.ReadLine();
                if (line == null) return null;
                foreach (var token in line.Split(_whiteSpaces, StringSplitOptions.RemoveEmptyEntries))
                {
                    Tokens.Enqueue(token);
                }
            }
            return Tokens.Count == 0 ? null : Tokens.Dequeue();
        }

        private readonly char[] _whiteSpaces = { ' ', '\r', '\n', '\t' };

        static void Main()
        {
            new Thread(new Solution().run, 64 * 1024 * 1024).Start();
        }

        #endregion
    }
}

namespace kp.Algo { }
