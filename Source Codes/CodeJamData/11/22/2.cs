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
		private const bool UseMultiThreading = true;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\B-Large.in";
		private const string OutputFile = @"B-Large.out";

		class Point
		{
			public int x, cnt;
		}

		private int n, d;
		private Point[] pts;
		private double res;

		void ReadData()
		{
			n = NextInt();
			d = NextInt();
			pts = new Point[n];
			for ( int i = 0; i < n; ++i )
			{
				pts[i] = new Point { x = NextInt(), cnt = NextInt() };
			}
		}

		bool can( double time )
		{
			double l = -1e20;
			for ( int i = 0; i < n; ++i )
			{
				for ( int j = 0; j < pts[i].cnt; ++j )
				{
					l += d;
					double p = pts[i].x;
					if ( l <= p ) p = Math.Max( p - time, l );
					else p = Math.Min( p + time, l );
					if ( p < l ) return false;
					l = p;
				}
			}
			return true;
		}

		void Solve()
		{
			double l = 0, r = 1e20;
			for ( int t = 0; t < 100; ++t )
			{
				double m = ( l + r ) / 2;
				if ( can( m ) ) r = m; else l = m;
			}
			res = l;
		}

		void WriteAnswer()
		{
			Out.WriteLine( res.ToString( "0.0000000000", CultureInfo.InvariantCulture ) );
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
