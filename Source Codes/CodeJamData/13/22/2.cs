
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
		private const string InputFile = @"C:\Users\Pavel\Downloads\B-Large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2013 1B\B-Large.out";

		private int n, x, y;
		private double res;

		void ReadData()
		{
			n = NextInt();
			x = NextInt();
			y = NextInt();
		}

		void Solve()
		{
			int level = ( Math.Abs( x ) + Math.Abs( y ) ) / 2;
			int sum = 0, l = 1;
			for ( int i = 0; i < level && sum <= n; ++i )
			{
				sum += 2 * l - 1;
				l += 2;
			}
			if ( sum >= n )
			{
				res = 0;
				return;
			}
			n -= sum;
			if ( n >= 2 * l - 1 )
			{
				res = 1;
				return;
			}
			if ( y == l - 1 || n < y + 1 )
			{
				res = 0;
				return;
			}

			double[] dpL = new double[n + 1];

			dpL[0] = 1;
			for ( int i = 0; i < n; ++i )
			{
				double[] next = new double[n + 1];
				for ( int j = 0; j <= i + 1; ++j )
				{
					next[j] = dpL[j] * ( i - j == l - 1 ? 0.0 : j == l - 1 ? 1 : 0.5 );
					if ( j > 0 ) next[j] += dpL[j - 1] * ( i - j + 1 == l - 1 ? 1.0 : j - 1 == l - 1 ? 0 : 0.5 );
				}

				dpL = next;
			}

			for ( int i = y + 1; i <= n; ++i ) res += dpL[i];
		}

		void WriteAnswer()
		{
			Out.WriteLine( res.ToString( "0.000000000000000000", CultureInfo.InvariantCulture ) );
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
