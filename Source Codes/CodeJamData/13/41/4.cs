
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
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\A-Small-attempt1.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2013 2\A-Small.out";

		private int n, m, ans;
		private int[] from, to, cnt;

		void ReadData()
		{
			n = NextInt();
			m = NextInt();
			from = new int[m];
			to = new int[m];
			cnt = new int[m];
			for ( int i = 0; i < m; ++i )
			{
				from[i] = NextInt() - 1;
				to[i] = NextInt() - 1;
				cnt[i] = NextInt();
			}
		}

		private const int MOD = 1000002013;

		int GetCost( int dist )
		{
			return n * dist - dist * ( dist - 1 ) / 2;
		}

		void Solve()
		{
			ans = 0;
			for ( int i = 0; i < m; ++i )
			{
				ans += GetCost( to[i] - from[i] ) * cnt[i];
			}
			var f = new List<int>[n];
			for ( int j = 0; j < n; ++j )
				f[j] = new List<int>();
			for ( int j = 0; j < m; ++j )
				for ( int t = 0; t < cnt[j]; ++t )
					f[to[j]].Add( from[j] );
			for ( int i = 0; i < n; ++i )
				foreach ( var u in f[i] )
				{
					int myDist = GetCost( i - u ), bestDist = int.MaxValue, bestJ = -1, bestT = -1;
					for ( int j = i + 1; j < n; ++j )
					{
						int curT = -1;
						foreach ( var v in f[j] )
						{
							++curT;
							if ( v > i ) continue;
							int curDist = GetCost( i - v );
							if ( curDist < bestDist )
							{
								bestDist = curDist;
								bestJ = j;
								bestT = curT;
							}
						}
					}
					if ( bestJ != -1 )
					{
						if ( bestDist < myDist )
						{
							ans -= bestDist;
							f[bestJ][bestT] = u;
						}
						else ans -= myDist;
					}
					else
					{
						ans -= myDist;
					}
				}
		}

		void WriteAnswer()
		{
			Out.WriteLine( ans );
		}

		#region ...

		void run()
		{
			if ( UseStandardIO )
			{
				_inputStream = Console.In;
				_outputStream = Console.Out;
			}
			else
			{
				_inputStream = File.OpenText( InputFile );
				_outputStream = File.CreateText( Path.Combine( new FileInfo( GetType().Assembly.Location ).Directory.Parent.Parent.Parent.FullName, OutputFile ) );
			}

			int testsCount = int.Parse( _inputStream.ReadLine() );
			var solvers = new Solution[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new Solution();
				solvers[i].ReadData();
			}

			int done = 0;
			if ( UseMultiThreading )
			{
				solvers.AsParallel().WithDegreeOfParallelism( Math.Max( Environment.ProcessorCount, 2 ) ).ForAll(
					solver => { solver.Solve(); Console.Title = ( ++done ).ToString() + " of " + testsCount; } );
			}
			else
			{
				for ( int i = 0; i < testsCount; ++i )
				{
					solvers[i].Solve();
					Console.Title = ( ++done ).ToString() + " of " + testsCount;
				}
			}
			for ( int i = 0; i < testsCount; ++i )
			{
				Out.Write( string.Format( "Case #{0}: ", i + 1 ) );
				solvers[i].WriteAnswer();
			}
			Out.Flush();
			if ( UseStandardIO )
			{
				Console.ReadLine();
			}
			else
			{
				Out.Close();
			}
		}

		static TextWriter Out { get { return _outputStream; } }

		private static TextReader _inputStream;
		private static TextWriter _outputStream;

		public BigInteger NextBigInteger()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return BigInteger.Parse( token );
		}

		public double NextDouble()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return double.Parse( token, CultureInfo.InvariantCulture );
		}

		public long NextLong()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return long.Parse( token );
		}

		public int NextInt()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return int.Parse( token );
		}

		private static readonly Queue<string> Tokens = new Queue<string>();
		public string NextToken()
		{
			if ( Tokens.Count > 0 )
			{
				return Tokens.Dequeue();
			}
			while ( Tokens.Count == 0 )
			{
				var line = _inputStream.ReadLine();
				if ( line == null ) return null;
				foreach ( var token in line.Split( _whiteSpaces, StringSplitOptions.RemoveEmptyEntries ) )
				{
					Tokens.Enqueue( token );
				}
			}
			return Tokens.Count == 0 ? null : Tokens.Dequeue();
		}

		private readonly char[] _whiteSpaces = { ' ', '\r', '\n', '\t' };

		static void Main()
		{
			new Thread( new Solution().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}

namespace kp.Algo { }
