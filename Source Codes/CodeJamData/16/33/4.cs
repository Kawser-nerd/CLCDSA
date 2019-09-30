
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
        private const string InputFile = @"C:\Users\kp\Downloads\C-small-attempt0.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2016 1C\C-Small.out";

        int J, P, S, K;
        int ans;
        List<Tuple<int, int, int>> best;

        void ReadData()
        {
            J = NextInt();
            P = NextInt();
            S = NextInt();
            K = NextInt();
        }

        void Solve()
        {
            var combs = new List<Tuple<int, int, int>>();
            for (int i = 0; i < J; i++)
            {
                for (int j = 0; j < P; j++)
                {
                    for (int t = 0; t < S; t++)
                    {
                        combs.Add(new Tuple<int, int, int>(1 + i, 4 + j, 7 + t));
                    }
                }
            }

            best = null;
            int[] seen = new int[1000];
            ans = 0;
            var rand = new Random();
            Tuple<int, int, int> tmp;
            for (int times = 0; times < 1000000; times++)
            {
                for (int i = 1; i < combs.Count; i++)
                {
                    int u = rand.Next(i + 1);
                    if (u != i)
                    {
                        tmp = combs[i];
                        combs[i] = combs[u];
                        combs[u] = tmp;
                    }
                }

                Array.Clear(seen, 0, seen.Length);
                int cur = 0;
                for (int i = 0; i < combs.Count; i++)
                {
                    var key = combs[i].Item1 + combs[i].Item2 * 10 + combs[i].Item3 * 100;
                    if (++seen[key] > 1)
                    {
                        break;
                    }

                    key = combs[i].Item1 + combs[i].Item2 * 10;
                    if (++seen[key] > K)
                    {
                        break;
                    }

                    key = combs[i].Item1 + combs[i].Item3 * 100;
                    if (++seen[key] > K)
                    {
                        break;
                    }

                    key = combs[i].Item2 * 10 + combs[i].Item3 * 100;
                    if (++seen[key] > K)
                    {
                        break;
                    }



                    ++cur;
                }
                if (cur > ans)
                {
                    ans = cur;
                    best = new List<Tuple<int, int, int>>(combs.Take(ans));
                }
            }
        }

        void WriteAnswer()
        {
            Out.WriteLine(ans);
            foreach (var tp in best)
            {
                Out.WriteLine(tp.Item1 + " " + (tp.Item2 - 3) + " " + (tp.Item3 - 6));
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
