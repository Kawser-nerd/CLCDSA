
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
        private const string InputFile = @"C:\Users\kp\Downloads\D-Large.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2017 Qual\D.cs" + ".output.txt";
        private const bool UseMultiThreading = true;

        int n, m;
        char[,] map;
        char[,] ansMap;

        void ReadData()
        {
            n = NextInt();
            m = NextInt();
            map = new char[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    map[i, j] = '.';
                }
            }
            for (int i = 0; i < m; i++)
            {
                var ch = NextToken()[0];
                var row = NextInt() - 1;
                var col = NextInt() - 1;
                map[row, col] = ch;
            }
        }

        void Solve()
        {
            var vertices = n + n + 2 * n - 1 + 2 * n - 1 + 2;
            var s = vertices - 2;
            var t = vertices - 1;
            var g = new kp.Algo.Graphs.MaxFlowGraph(vertices);

            var rowTaken = new bool[n];
            var colTaken = new bool[n];
            var plusDiagTaken = new bool[2 * n - 1];
            var minusDiagTaken = new bool[2 * n - 1];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    switch (map[i, j])
                    {
                        case 'o':
                            rowTaken[i] = true;
                            colTaken[j] = true;
                            plusDiagTaken[i + j] = true;
                            minusDiagTaken[i - j + n - 1] = true;
                            break;
                        case 'x':
                            rowTaken[i] = true;
                            colTaken[j] = true;
                            break;
                        case '+':
                            plusDiagTaken[i + j] = true;
                            minusDiagTaken[i - j + n - 1] = true;
                            break;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (!rowTaken[i])
                {
                    g.AddDirectedEdge(s, i, 1);
                }
                if (!colTaken[i])
                {
                    g.AddDirectedEdge(i + n, t, 1);
                }
            }

            for (int i = 0; i < 2 * n - 1; i++)
            {
                if (!plusDiagTaken[i])
                {
                    g.AddDirectedEdge(s, i + 2 * n, 1);
                }
                if (!minusDiagTaken[i])
                {
                    g.AddDirectedEdge(i + 2 * n + 2 * n - 1, t, 1);
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    g.AddDirectedEdge(i, j + n, 1);
                }
            }

            for (int i = 0; i < 2 * n - 1; i++)
            {
                for (int j = 0; j < 2 * n - 1; j++)
                {
                    var r2 = i + j - n + 1;
                    var r = r2 / 2;
                    if (r2 % 2 == 0 && r >= 0 && r < n)
                    {
                        var c = i - r;
                        if (c >= 0 && c < n)
                        {
                            g.AddDirectedEdge(i + 2 * n, j + 2 * n + 2 * n - 1, 1);
                        }
                    }
                }
            }

            g.MaxFlow(s, t);

            ansMap = (char[,])map.Clone();

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (g.Flow[i, j + n] > 0)
                    {
                        if (ansMap[i, j] == '.')
                        {
                            ansMap[i, j] = 'x';
                        }
                        else if (ansMap[i, j] == '+')
                        {
                            ansMap[i, j] = 'o';
                        }
                        else
                        {
                            throw new Exception();
                        }
                    }
                }
            }

            for (int i = 0; i < 2 * n - 1; i++)
            {
                for (int j = 0; j < 2 * n - 1; j++)
                {
                    var r2 = i + j - n + 1;
                    var r = r2 / 2;
                    if (r2 % 2 == 0 && r >= 0 && r < n)
                    {
                        var c = i - r;
                        if (c >= 0 && c < n)
                        {
                            if (g.Flow[i + 2 * n, j + 2 * n + 2 * n - 1] > 0)
                            {
                                if (ansMap[r, c] == '.')
                                {
                                    ansMap[r, c] = '+';
                                }
                                else if (ansMap[r, c] == 'x')
                                {
                                    ansMap[r, c] = 'o';
                                }
                                else
                                {
                                    throw new Exception();
                                }
                            }
                        }
                    }
                }
            }
        }

        void WriteAnswer()
        {
            int res = 0;
            var added = new List<string>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (ansMap[i, j] == 'o') res += 2;
                    else if (ansMap[i, j] != '.') res++;

                    if (ansMap[i, j] != map[i, j])
                    {
                        added.Add(string.Format("{0} {1} {2}", ansMap[i, j], i + 1, j + 1));
                    }
                }
            }

            Out.WriteLine(res + " " + added.Count);
            foreach (var a in added)
            {
                Out.WriteLine(a);
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


namespace kp.Algo.Graphs
{
public class MaxFlowGraph
	{
		public const int Inf = 1000000000;
		public readonly int N;
		public readonly int[,] Mates;
		public readonly int[,] Capacity;
		public int[,] Flow;

		public MaxFlowGraph( int numVertices )
		{
			N = numVertices;
			Mates = new int[N, N + 1];
			Capacity = new int[N, N];
			Flow = new int[N, N];
		}

		public void AddUndirectedEdge( int u, int v, int capacity )
		{
			Capacity[u, v] += capacity;
			Capacity[v, u] += capacity;
			Mates[u, ++Mates[u, 0]] = v;
			Mates[v, ++Mates[v, 0]] = u;
		}

		public void AddDirectedEdge( int u, int v, int capacity )
		{
			Capacity[u, v] += capacity;
			Mates[u, ++Mates[u, 0]] = v;
			Mates[v, ++Mates[v, 0]] = u;
		}

		private int[] _h, _e, _cur;
		private Queue<int> _q;
		public int MaxFlow( int from, int to )
		{
			_h = new int[N]; _e = new int[N]; _cur = new int[N];
			Flow = new int[N, N];
			_h[from] = N;
			for ( int i = 0; i < N; ++i ) _cur[i] = 1;
			_q = new Queue<int>();
			for ( int i = 1; i <= Mates[from, 0]; ++i )
			{
				int v = Mates[from, i];
				Flow[from, v] = Capacity[from, v];
				Flow[v, from] = -Flow[from, v];
				_e[v] = Capacity[from, v];
				_q.Enqueue( v );
			}
			while ( _q.Count > 0 )
			{
				int u = _q.Dequeue();
				if ( u == from || u == to ) continue;
				Relax( u );
			}
			return _e[to];
		}

		void Lift( int u )
		{
			int minh = Inf;
			for ( int i = 1; i <= Mates[u, 0]; ++i )
			{
				int v = Mates[u, i];
				if ( Capacity[u, v] - Flow[u, v] > 0 ) minh = Math.Min( minh, _h[v] );
			}
			_h[u] = minh + 1;
		}

		void Push( int u, int v )
		{
			int d = Math.Min( Capacity[u, v] - Flow[u, v], _e[u] );
			_e[u] -= d; Flow[u, v] += d; Flow[v, u] = -Flow[u, v]; _e[v] += d;
		}

		void Relax( int u )
		{
			while ( _e[u] > 0 )
			{
				int v = Mates[u, _cur[u]];
				if ( _cur[u] > Mates[u, 0] )
				{
					Lift( u );
					_cur[u] = 1;
				}
				else if ( Capacity[u, v] - Flow[u, v] > 0 && _h[u] == _h[v] + 1 )
				{
					Push( u, v );
					_q.Enqueue( v );
					++_cur[u];
				}
				else ++_cur[u];
			}
		}
	}
}
