using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemA
{
	class A
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\A-Large.in";
		private const string OutputFile = @"A-Large.out";

		private int n;
		private string[] data;

		void ReadData()
		{
			n = NextInt();
			data = new string[n];
			for ( int i = 0; i < n; ++i ) data[i] = NextToken();
		}

		private double[] res;
		void Solve()
		{
			res = new double[n];
			double[] wp = new double[n];
			double[] owp = new double[n];
			double[] oowp = new double[n];
			for ( int i = 0; i < n; ++i )
			{
				int wins = 0, games = 0;
				for ( int j = 0; j < n; ++j ) if ( data[i][j] == '1' )
					{
						++wins;
						++games;
					}
					else if ( data[i][j] == '0' )
					{
						++games;
					}
				wp[i] = (double)wins / games;
			}
			for ( int i = 0; i < n; ++i )
			{
				for ( int j = 0; j < n; ++j ) if ( i != j && data[i][j] != '.' )
					{
						int wins = 0, games = 0;
						for ( int k = 0; k < n; ++k )
							if ( k != i )
							{
								if ( data[j][k] == '1' )
								{
									++wins;
									++games;
								}
								else if ( data[j][k] == '0' )
								{
									++games;
								}
							}
						owp[i] += (double)wins / games;
					}
				int ops = 0;
				for ( int j = 0; j < n; ++j ) if ( data[i][j] != '.' ) ++ops;
				owp[i] /= ops;
			}
			for ( int i = 0; i < n; ++i )
			{
				for ( int j = 0; j < n; ++j ) if ( i != j && data[i][j] != '.' ) oowp[i] += owp[j];
				int ops = 0;
				for ( int j = 0; j < n; ++j ) if ( data[i][j] != '.' ) ++ops;
				oowp[i] /= ops;
			}
			for ( int i = 0; i < n; ++i )
			{
				res[i] = 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i];
			}
		}

		void WriteAnswer()
		{
			for ( int i = 0; i < n; ++i ) Out.WriteLine( res[i].ToString( "0.0000000000", CultureInfo.InvariantCulture ) );
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
			var solvers = new A[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new A();
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
				Out.WriteLine( string.Format( "Case #{0}: ", i + 1 ) );
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
			new Thread( new A().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}
