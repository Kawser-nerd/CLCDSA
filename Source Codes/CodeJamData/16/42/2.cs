
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
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2016 2\B.cs" + ".output.txt";
        private const bool UseMultiThreading = false;

        int n, k;
        double[] p;
        double ans;

        void ReadData()
        {
            n = NextInt();
            k = NextInt();
            p = new double[n];
            for (int i = 0; i < n; i++)
            {
                p[i] = NextDouble();
            }
        }

        void Solve()
        {
            ans = 0;
            var ids = new int[k];
            Array.Sort(p);
            double[,] dp = new double[202, 202];
            for (int f = 0; f <= k; f++)
            {
                int z = 0;
                int l = k - f;
                for (int i = 0; i < f; i++)
                {
                    ids[z++] = i;
                }
                for (int i = 0; i < l; i++)
                {
                    ids[z++] = n - 1 - i;
                }

                dp[0, 0] = 1;
                for (int i = 1; i <= k; i++)
                {
                    for (int j = 0; j <= i; ++j)
                    {
                        dp[i, j] = p[ids[i - 1]] * (j == 0 ? 0 : dp[i - 1, j - 1]) + (1 - p[ids[i - 1]]) * dp[i - 1, j];
                    }
                }

                ans = Math.Max(ans, dp[k, k / 2]);
            }
        }

        void SolveSmall()
        {
            ans = 0;
            var ids = new int[k];
            double[,] dp = new double[20, 40];
            for (int mask = 0; mask < 1 << n; ++mask)
            {
                if (BitUtils.CountOnes(mask) != k) continue;

                int z = 0;
                for (int i = 0; i < n; i++)
                {
                    if (BitUtils.BitInMask(mask, i)) ids[z++] = i;
                }

                dp[0, 0] = 1;
                for (int i = 1; i <= k; i++)
                {
                    for (int j = 0; j <= i; ++j)
                    {
                        dp[i, j] = p[ids[i - 1]] * (j == 0 ? 0 : dp[i - 1, j - 1]) + (1 - p[ids[i - 1]]) * dp[i - 1, j];
                    }
                }

                ans = Math.Max(ans, dp[k, k / 2]);
            }
        }

        void WriteAnswer()
        {
            Out.WriteLine(ans.ToString("0.00000000000000000", CultureInfo.InvariantCulture));
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
	static class BitUtils
	{
		public static int CountOnes( int x )
		{
			if ( x < 0 ) throw new Exception( "Can't count bits in negative number" );
			int res = 0;
			while ( x > 0 )
			{
				++res;
				x &= ( x - 1 );
			}
			return res;
		}
		public static bool BitInMask( int mask, int bit )
		{
			return ( mask & ( 1 << bit ) ) != 0;
		}
	}
}
