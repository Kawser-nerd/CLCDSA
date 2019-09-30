
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
        private const bool UseMultiThreading = false;
        private const bool IsTestingRun = false;
        private const string InputFile = @"C:\Users\kp\Downloads\A-large.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2016 1C\A-Small.out";

        int n;
        int[] p;
        List<string> ans;

        void ReadData()
        {
            n = NextInt();
            p = new int[n];
            for (int i = 0; i < n; i++)
            {
                p[i] = NextInt();
            }
        }

        void Solve()
        {
            ans = new List<string>();
            var all = new List<Tuple<int, char>>();
            for (int i = 0; i < n; i++)
            {
                all.Add(new Tuple<int, char>(p[i], (char)('A' + i)));
            }
            while (all.Any())
            {
                all.Sort();

                if (all.Count == 2 && all[0].Item1 == all[1].Item1)
                {
                    ans.Add("" + all[0].Item2 + all[1].Item2);
                    all[0] = new Tuple<int, char>(all[0].Item1 - 1, all[0].Item2);
                    all[1] = new Tuple<int, char>(all[1].Item1 - 1, all[1].Item2);
                }
                else if (all.Count == 1 && all[all.Count - 1].Item1 > 1)
                {
                    ans.Add("" + all[all.Count - 1].Item2 + all[all.Count - 1].Item2);
                    all[all.Count - 1] = new Tuple<int, char>(all[all.Count - 1].Item1 - 2, all[all.Count - 1].Item2);
                }
                else if (all.Count > 1 && all[all.Count - 1].Item1 - 1 > all[all.Count - 2].Item1)
                {
                    ans.Add("" + all[all.Count - 1].Item2 + all[all.Count - 1].Item2);
                    all[all.Count - 1] = new Tuple<int, char>(all[all.Count - 1].Item1 - 2, all[all.Count - 1].Item2);
                }
                else
                {
                    ans.Add("" + all[all.Count - 1].Item2);
                    all[all.Count - 1] = new Tuple<int, char>(all[all.Count - 1].Item1 - 1, all[all.Count - 1].Item2);
                }

                all.RemoveAll(e => e.Item1 == 0);
            }
        }

        void WriteAnswer()
        {
            var s = "";
            foreach (var ss in ans)
            {
                if (s != "") s += " ";
                s += ss;
            }
            Out.WriteLine(s);
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
                solvers.AsParallel().WithDegreeOfParallelism(Math.Max(Environment.ProcessorCount, 2)).ForAll(
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
