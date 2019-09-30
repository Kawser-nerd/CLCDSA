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
		private const string InputFile = @"C:\Users\kp\Downloads\A-Large.in";
		private const string OutputFile = @"..\A-Large.out";

		private int n;
		private int[] s;
		private double[] ans;

		void ReadData()
		{
			n = NextInt();
			s = new int[n];
			for ( int i = 0; i < n; ++i ) s[i] = NextInt();
		}

		void Solve()
		{
			ans = new double[n];
			for ( int i = 0; i < n; ++i )
			{
				if ( can( i, 0 ) ) continue;
				double l = 0, r = 1;
				for ( int times = 0; times < 400; ++times )
				{
					double m = ( l + r ) / 2;
					if ( can( i, m ) ) r = m; else l = m;
				}
				ans[i] = r * 100;
			}
		}

		private bool can( int u, double m )
		{
			double rest = 1 - m;
			int sum = 0;
			for ( int i = 0; i < n; ++i ) sum += s[i];
			double my = s[u] + sum * m, need = 0;
			for ( int i = 0; i < n; ++i )
				if ( i != u && s[i] <= my )
				{
					need += ( my - s[i] ) / sum;
				}
			return need >= rest;
		}

		void WriteAnswer()
		{
			for ( int i = 0; i < n; ++i )
			{
				if ( i > 0 ) Out.Write( " " );
				Out.Write( ans[i].ToString( "0.0000000000", CultureInfo.InvariantCulture ) );
			}
			Out.WriteLine();
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
