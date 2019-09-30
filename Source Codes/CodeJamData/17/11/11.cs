
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
        private const string InputFile = @"C:\Users\kp\Downloads\A-Large.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2017 1A\A.cs" + ".output.txt";
        private const bool UseMultiThreading = true;

        int rows, cols;
        string[] s;

        void ReadData()
        {
            rows = NextInt();
            cols = NextInt();
            s = new string[rows];
            for (int i = 0; i < rows; i++)
            {
                s[i] = NextToken();
            }
        }

        int[] l, r, t, b;

        void Solve()
        {
            l = new int[26];
            r = new int[26];
            t = new int[26];
            b = new int[26];
            ArrayUtils.Fill(l, 100);
            ArrayUtils.Fill(r, -1);
            ArrayUtils.Fill(t, 100);
            ArrayUtils.Fill(b, -1);

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (s[i][j] != '?')
                    {
                        l[s[i][j] - 'A'] = Math.Min(l[s[i][j] - 'A'], j);
                        r[s[i][j] - 'A'] = Math.Max(r[s[i][j] - 'A'], j);
                        t[s[i][j] - 'A'] = Math.Min(t[s[i][j] - 'A'], i);
                        b[s[i][j] - 'A'] = Math.Max(b[s[i][j] - 'A'], i);
                    }
                }
            }

            found = false;
            Go(0, 0);
            if (!found) throw new Exception();
        }

        bool found;

        private void Go(int row, int col)
        {
            if (found) return;

            if (col == cols)
            {
                Go(row + 1, 0);
                return;
            }

            if (row == rows)
            {
                found = true;
                return;
            }

            bool free = true;
            for (int i = 0; i < 26; i++)
            {
                if (r[i] == -1) continue;

                if (l[i] <= col && r[i] >= col && t[i] <= row && b[i] >= row)
                {
                    free = false;
                    break;
                }
            }

            if (!free)
            {
                Go(row, col + 1);
                return;
            }

            List<int> canBe = null;

            for (int i = 0; i < 26; i++)
            {
                if (r[i] == -1) continue;

                bool ok = true;
                for (int j = 0; j < 26; j++)
                {
                    if (j == i || r[j] == -1) continue;

                    if (Cross(Math.Min(l[i], col), Math.Max(r[i], col), Math.Min(t[i], row), Math.Max(b[i], row), l[j], r[j], t[j], b[j]))
                    {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                {
                    if (canBe == null) canBe = new List<int>();
                    canBe.Add(i);
                }
            }

            if (canBe == null) return;

            foreach (var i in canBe)
            {
                var ol = l[i];
                var or = r[i];
                var ot = t[i];
                var ob = b[i];
                l[i] = Math.Min(l[i], col);
                r[i] = Math.Max(r[i], col);
                t[i] = Math.Min(t[i], row);
                b[i] = Math.Max(b[i], row);
                Go(row, col + 1);

                if (found) return;

                l[i] = ol;
                r[i] = or;
                t[i] = ot;
                b[i] = ob;
            }
        }

        private bool Cross(int l1, int r1, int t1, int b1, int l2, int r2, int t2, int b2)
        {
            if (l1 > r2 || l2 > r1) return false;
            if (t1 > b2 || t2 > b1) return false;

            return true;
        }

        void WriteAnswer()
        {
            Out.WriteLine();
            var ans = new char[rows][];
            for (int i = 0; i < rows; i++)
            {
                ans[i] = new char[cols];
            }

            for (int i = 0; i < 26; i++)
            {
                if (r[i] == -1) continue;

                for (int cc = l[i]; cc <= r[i]; cc++)
                {
                    for (int rr = t[i]; rr <= b[i]; rr++)
                    {
                        ans[rr][cc] = (char)(i + 'A');
                    }
                }
            }

            for (int i = 0; i < rows; i++)
            {
                Out.WriteLine(new string(ans[i]));
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

namespace kp.Algo
{
	static class ArrayUtils
	{
		public static void Fill<T>( T[] a, T value )
		{
			for ( int i = 0; i < a.Length; ++i ) a[i] = value;
		}
	}
}
