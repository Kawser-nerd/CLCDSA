using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemB
{
	class B
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\B-Small-attempt0.in";
		private const string OutputFile = @"B-Small.out";

		private int rows, cols, d, res;
		private char[,] s;

		void ReadData()
		{
			res = -1;
			rows = NextInt();
			cols = NextInt();
			d = NextInt();
			s = new char[rows, cols];
			for ( int i = 0; i < rows; ++i )
			{
				var ss = NextToken();
				for ( int j = 0; j < cols; ++j ) s[i, j] = ss[j];
			}
		}

		void Solve()
		{
			for ( int k = 3; k <= Math.Min( rows, cols ); ++k )
				for ( int r = 0; r < rows - k + 1; ++r )
					for ( int c = 0; c < cols - k + 1; ++c )
					{
						int cx = 0, cy = 0;
						for ( int i = 0; i < k; ++i )
						{
							cx += d * ( i + c );
							cy += d * ( i + r );
						}

						int tx = 0, ty = 0, sum = 0;
						for ( int i = 0; i < k; ++i )
							for ( int j = 0; j < k; ++j )
							{
								if ( i == 0 && j == 0 ) continue;
								if ( i == 0 && j == k - 1 ) continue;
								if ( i == k - 1 && j == 0 ) continue;
								if ( i == k - 1 && j == k - 1 ) continue;
								tx += ( d + s[i + r, j + c] - '0' ) * ( j + c );
								ty += ( d + s[i + r, j + c] - '0' ) * ( i + r );
								sum += d + s[i + r, j + c] - '0';
							}
						if ( (long)tx * k * d == cx * sum && (long)ty * k * d == cy * sum )
						{
							res = Math.Max( res, k );
						}
					}
		}

		void WriteAnswer()
		{
			Out.WriteLine( res == -1 ? "IMPOSSIBLE" : res.ToString() );
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
			var solvers = new B[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new B();
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
			new Thread( new B().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}
