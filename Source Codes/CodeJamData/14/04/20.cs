
using System;
using System.Collections.Generic;
using System.Data;
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
		private const string InputFile = @"D-Large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2014 1A\D-Large.out";

		private int n, ans1, ans2;
		private double[] a, b;

		void ReadData()
		{
			n = NextInt();
			a = new double[n];
			b = new double[n];
			for ( int i = 0; i < n; i++ )
			{
				a[i] = NextDouble();
			}
			for ( int i = 0; i < n; i++ )
			{
				b[i] = NextDouble();
			}
		}

		void Solve()
		{
			Array.Sort( a );
			Array.Sort( b );
			ans1 = Solve1();
			ans2 = Solve2();
		}

		private int Solve2()
		{
			int res = 0;
			var used = new bool[n];
			for ( int i = 0; i < n; i++ )
			{
				int u = -1;
				for ( int j = 0; j < n; j++ )
				{
					if ( !used[j] && b[j] > a[i] )
					{
						u = j;
						break;
					}
				}
				if ( u == -1 )
				{
					for ( int j = 0; j < n; j++ )
					{
						if ( !used[j] )
						{
							u = j;
							break;
						}
					}
				}

				used[u] = true;
				if ( a[i] > b[u] ) ++res;
			}

			return res;
		}

		private int Solve1()
		{
			var dp = new int[n, n];
			for ( int len = 1; len <= n; len++ )
			{
				for ( int l = 0; l < n - len + 1; l++ )
				{
					int r = l + len - 1;

					dp[l, r] = ( a[n - len] > b[r] ? 1 : 0 ) + ( len == 1 ? 0 : dp[l, r - 1] );
					if ( a[n - len] > b[l] )
						dp[l, r] = Math.Max( dp[l, r], 1 + ( len == 1 ? 0 : dp[l + 1, r] ) );
				}
			}

			return dp[0, n - 1];
		}

		void WriteAnswer()
		{
			Out.WriteLine( string.Format( "{0} {1}", ans1, ans2 ) );
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
				_inputStream = File.OpenText( Path.Combine( Path.Combine( Environment.GetFolderPath( Environment.SpecialFolder.UserProfile ), "Downloads" ), InputFile ) );
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
