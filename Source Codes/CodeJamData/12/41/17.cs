using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemA
{
	internal class A
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\A-Large.in";
		private const string OutputFile = @"..\A-Large.out";

		private int n, D;
		private int[] d, l;
		private bool res;

		void ReadData()
		{
			n = NextInt();
			d = new int[n];
			l = new int[n];
			for ( int i = 0; i < n; ++i )
			{
				d[i] = NextInt();
				l[i] = NextInt();
			}
			D = NextInt();
			res = false;
		}

		void Solve()
		{
			bool[] can = new bool[n];
			int[] dist = new int[n];
			for ( int i = 0; i < n; ++i )
				dist[i] = int.MaxValue;
			dist[0] = d[0];
			int first = 1;
			for ( int i = 0; i < n; ++i )
			{
				for ( ; first < n; ++first )
				{
					if ( dist[i] >= d[first] - d[i] )
					{
						dist[first] = Math.Min( l[first], d[first] - d[i] );
					}
					else break;
				}
			}
			for ( int i = 0; i < n; ++i )
				if ( dist[i] < int.MaxValue && d[i] + dist[i] >= D )
				{
					res = true;
					break;
				}
		}


		void WriteAnswer()
		{
			if ( res )
				Out.WriteLine( "YES" );
			else Out.WriteLine( "NO" );
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
			new Thread( new A().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}
