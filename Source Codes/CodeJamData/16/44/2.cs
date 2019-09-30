
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
        private const string InputFile = @"C:\Users\kp\Downloads\D-Small-attempt0.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2016 2\D.cs" + ".output.txt";
        private const bool UseMultiThreading = false;

        int n;
        int[,] a;
        int ans;

        void ReadData()
        {
            n = NextInt();
            a = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                var s = NextToken();
                for (int j = 0; j < n; j++)
                {
                    a[i, j] = s[j] - '0';
                }
            }
        }

        void Solve()
        {
            ans = int.MaxValue;
            Go(0, 0, 0);
        }

        void Go(int r, int c, int add)
        {
            if (r == n)
            {
                if (Ok())
                {
                    ans = Math.Min(ans, add);
                }
                return;
            }
            if (c == n)
            {
                Go(r + 1, 0, add);
                return;
            }

            if (a[r, c] == 1)
            {
                Go(r, c + 1, add);
                return;
            }
            else
            {
                Go(r, c + 1, add);
                a[r, c] = 1;
                Go(r, c + 1, add + 1);
                a[r, c] = 0;
            }
        }

        private bool Ok()
        {
            var p = PermutationUtils.First(n);

            do
            {
                bool[] could = new bool[1 << n];
                could[0] = true;
                for (int ii = 0; ii < n; ii++)
                {
                    int i = p[ii];

                    int mask = 0;
                    for (int j = 0; j < n; j++)
                    {
                        if (a[i, j] == 1) mask |= (1 << j);
                    }
                    bool bad = false;
                    for (int j = 0; j < (1 << n); j++)
                    {
                        if (could[j] && (j & mask) == mask)
                        {
                            bad = true;
                            break;
                        }
                    }
                    if (bad) return false;

                    bool[] could2 = new bool[1 << n];
                    for (int j = 0; j < (1 << n); j++)
                    {
                        if (could[j])
                        {
                            for (int k = 0; k < n; k++)
                            {
                                if (a[i, k] == 1) could2[j | (1 << k)] = true;
                            }
                        }
                    }
                    could = could2;
                }
            } while (PermutationUtils.Next(p));
            return true;
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

namespace kp.Algo
{
	static class PermutationUtils
	{
		public static int[] First( int n )
		{
			int[] res = new int[n];
			for ( int i = 0; i < n; ++i ) res[i] = i;
			return res;
		}
		public static bool Next( int[] p )
		{
			if ( p.Length == 1 ) return false;
			int i = 0;
			++i;
			if ( i == p.Length ) return false;
			i = p.Length;
			--i;

			for ( ; ; )
			{
				int ii = i;
				--i;
				if ( p[i].CompareTo( p[ii] ) < 0 )
				{
					int j = p.Length;
					do
					{
						--j;
					} while ( p[i].CompareTo( p[j] ) >= 0 );
					int tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
					int l = ii, r = p.Length - 1;
					while ( l < r )
					{
						tmp = p[l];
						p[l] = p[r];
						p[r] = tmp;
						++l;
						--r;
					}
					return true;
				}
				if ( i == 0 )
				{
					int l = 0, r = p.Length - 1;
					while ( l < r )
					{
						int tmp = p[l];
						p[l] = p[r];
						p[r] = tmp;
						++l;
						--r;
					}
					return false;
				}
			}
		}
	}
}
