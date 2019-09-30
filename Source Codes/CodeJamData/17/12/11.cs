
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
        private const string InputFile = @"C:\Users\kp\Downloads\B-Large.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2017 1A\B.cs" + ".output.txt";
        private const bool UseMultiThreading = true;

        int n, p, ans;
        int[] r;
        int[,] q;

        void ReadData()
        {
            n = NextInt();
            p = NextInt();
            r = new int[n];
            for (int i = 0; i < n; i++)
            {
                r[i] = NextInt();
            }

            q = new int[n, p];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < p; j++)
                {
                    q[i, j] = NextInt();
                }
            }
        }

        void Solve()
        {
            ans = 0;

            int curK = 0;
            bool[,] taken = new bool[n, p];

            var takenJ = new int[n];

            while (curK <= 1000000)
            {
                bool ok = true;

                for (int i = 0; i < n; i++)
                {
                    int curJ = -1;
                    for (int j = 0; j < p; j++)
                    {
                        if (taken[i, j]) continue;

                        var l1 = (q[i, j] * 10 + r[i] * 11 - 1) / (r[i] * 11);
                        var r1 = (q[i, j] * 10) / (r[i] * 9);
                        if (l1 <= curK && curK <= r1)
                        {
                            if (curJ == -1 || q[i, curJ] > q[i, j])
                            {
                                curJ = j;
                            }
                        }
                    }

                    if (curJ == -1)
                    {
                        ok = false;
                        break;
                    }

                    takenJ[i] = curJ;
                }

                if (!ok)
                {
                    ++curK;
                }
                else
                {
                    ++ans;
                    for (int i = 0; i < n; i++)
                    {
                        taken[i, takenJ[i]] = true;
                    }
                }
            }
        }


        void WriteAnswer()
        {
            Out.WriteLine(ans);
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
