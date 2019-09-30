using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemD
{
	class D
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\D-Small-attempt0.in";
		private const string OutputFile = @"D-Small.out";

		private int k, n;
		private int[] keys, openWith;
		List<int>[] keysInside;
		private List<int> ans;

		void ReadData()
		{
			k = NextInt();
			n = NextInt();
			keys = new int[k];
			for ( int i = 0; i < k; ++i ) keys[i] = NextInt();
			openWith = new int[n];
			keysInside = new List<int>[n];
			for ( int i = 0; i < n; ++i )
			{
				openWith[i] = NextInt();
				int cnt = NextInt();
				keysInside[i] = new List<int>();
				for ( int j = 0; j < cnt; ++j ) keysInside[i].Add( NextInt() );
			}
		}

		void Solve()
		{
			dp = new bool?[1 << n];

			int mask = ( 1 << n ) - 1;
			if ( !Can( mask ) ) return;
			ans = new List<int>();
			for ( int t = 0; t < n; ++t )
			{
				var have = new List<int>( keys );
				for ( int i = 0; i < n; ++i )
					if ( ( mask & ( 1 << i ) ) == 0 )
					{
						have.AddRange( keysInside[i] );
					}

				for ( int i = 0; i < n; ++i )
					if ( ( mask & ( 1 << i ) ) == 0 )
					{
						if ( !have.Remove( openWith[i] ) )
							throw new ApplicationException();
					}

				for ( int j = 0; j < n; ++j )
					if ( ( mask & ( 1 << j ) ) != 0 && have.Contains( openWith[j] ) && Can( mask ^ ( 1 << j ) ) )
					{
						mask ^= ( 1 << j );
						ans.Add( j + 1 );
						break;
					}
			}
		}

		private bool?[] dp;
		private bool Can( int mask )
		{
			if ( mask == 0 ) return true;
			if ( dp[mask].HasValue )
				return dp[mask].Value;
			bool res = false;

			var have = new List<int>( keys );
			for ( int i = 0; i < n; ++i )
				if ( ( mask & ( 1 << i ) ) == 0 )
				{
					have.AddRange( keysInside[i] );
				}

			for ( int i = 0; i < n; ++i )
				if ( ( mask & ( 1 << i ) ) == 0 )
				{
					if ( !have.Remove( openWith[i] ) )
						throw new ApplicationException();
				}

			for ( int i = 0; i < n; ++i )
				if ( ( mask & ( 1 << i ) ) != 0 && have.Contains( openWith[i] ) && Can( mask ^ ( 1 << i ) ) )
				{
					res = true;
					break;
				}

			return ( dp[mask] = res ).Value;
		}

		void WriteAnswer()
		{
			if ( ans == null || ans.Count != n )
				Out.WriteLine( "IMPOSSIBLE" );
			else
			{
				for ( int i = 0; i < n; ++i )
				{
					Out.Write( ans[i] );
					if ( i < n - 1 ) Out.Write( " " );
				}
				Out.WriteLine();
			}
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
			var solvers = new D[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new D();
				solvers[i].ReadData();
			}

			int done = 0;
			if ( UseMultiThreading )
			{
				solvers.AsParallel().WithDegreeOfParallelism( Math.Max( Environment.ProcessorCount, 2 ) - 1 ).ForAll(
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
			new Thread( new D().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}
