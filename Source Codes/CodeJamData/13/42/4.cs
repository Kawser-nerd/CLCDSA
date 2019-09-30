
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
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\B-Large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2013 2\B-Large.out";

		private int n;
		private long p;
		private long ans1, ans2;

		void ReadData()
		{
			n = NextInt();
			p = NextLong();
		}

		long WorstPlace( long id )
		{
			long total = 1L << n;
			long cnt = id;
			long two = 1, pow = 0;
			while ( two <= cnt )
			{
				two *= 2;
				++pow;
			}
			--pow;
			long worstPlace = 1, add = total / 2;
			for ( int i = 0; i < pow; ++i )
			{
				worstPlace += add;
				add /= 2;
			}
			return worstPlace;
		}

		long BestPlace( long id )
		{
			long total = 1L << n;
			long cnt = total - id + 1;
			long two = 1, pow = 0;
			while ( two <= cnt )
			{
				two *= 2;
				++pow;
			}
			--pow;
			long bestPlace = total;
			for ( int i = 0; i < pow; ++i )
				bestPlace /= 2;
			return bestPlace;
		}

		void Solve()
		{
			long total = 1L << n;
			long l = 1, r = 1L << 60;
			if ( BestPlace( total ) <= p )
			{
				l = total;
			}
			else
			{
				while ( l + 1 < r )
				{
					long m = ( l + r ) / 2;
					if ( BestPlace( m ) <= p ) l = m;
					else r = m;
				}
			}
			ans2 = l;

			l = 1; r = 1L << 60;
			if ( WorstPlace( total ) <= p )
			{
				l = total;
			}
			else
			{
				while ( l + 1 < r )
				{
					long m = ( l + r ) / 2;
					if ( WorstPlace( m ) <= p ) l = m;
					else r = m;
				}
			}
			ans1 = l;
		}

		void WriteAnswer()
		{
			Out.WriteLine( ( ans1 - 1 ) + " " + ( ans2 - 1 ) );
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
